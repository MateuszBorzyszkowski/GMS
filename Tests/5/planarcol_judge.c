/*
  deskryptory:
stdin - test cases
3 - user out.
6 - error messages


sposob uzycia tego programu:
zakladamy, ze w pliku input znajduja sie dane testowe
mamy program prog.c, rozwiazujacy zadanie.
aby przetestowac program:

1) kompilujemy
gcc -o prog prog.c

2) generujemy wyjscie
./prog <input >output

3) kompilujemy ten plik
gcc -o planarcol_judge planarcol_judge.c

4) sprawdzamy, czy plik wyjsciowy jest poprawny
./planarcol_judge <input 3<output 6>err

5) jesli wystapily bledy, to komunikaty znajduja sie w pliku err.
   jesli plik err jest pusty, to wyscie jest poprawne, albo
   nastapil blad wykonania programu euler_judge i wowczas
   takie rozwiazanie nie jest akceptowane na spoju


*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int edges[3*MAX][2];
int m;
int n;

int coloring[MAX];

void Init() {
  int i;

  for ( i=0; i < n; i++ ) {
    coloring[i] = 0;
  }
  m = 0;
}


void ReadTestCase( FILE *file ) {
  int i;
  int u, v;
  char *tmp;

  Init();

  if ( fscanf( file, "Graph with %d nodes and %d edges:\n", &n, &m ) != 2 ) {
    tmp = "Wrong input file [1]\n";
    write( 6, tmp, strlen(tmp) );
    exit(1);
  }

  if ( m > 3*MAX ) {
    tmp = "Too many edges!!!\n";
    write( 6, tmp, strlen(tmp) );
    exit(1);
  }

  //printf( "%d\n", m );
  
  for ( i=0; i < m-1; i++ ) {
    fscanf( file, "{%d,%d},", &u, &v );
    edges[i][0] = u;
    edges[i][1] = v;
  }

  fscanf( file, "{%d,%d}\n", &u, &v );
  edges[m-1][0] = u;
  edges[m-1][1] = v;
}


void ReadUserOutput( FILE *fd ) {
  int u, c;
  int n_ = 0;
  

  for ( n_=0; n_ < n; n_++ ) {
    if ( fscanf( fd, "%d %d", &u, &c ) != 2 ) {
      write( 6, "Wrong output format\n", strlen("Wrong output format\n") );
      exit(1);
    }
    if ( u < 0 || u > n ) {
      write( 6, "Wrong vertex\n", strlen("Wrong vertex\n") );
      exit(1);
    }
    coloring[u] = c;
  }
}


void CheckSol( void ) {
  int i;
  char ss[1024];

  for ( i=0; i < n; i++ )
    if ( coloring[i] < 1 || coloring[i] > 6 ) {
      write( 6, "color not in 1,...,6\n", strlen("color not in 1,...,6\n") );
      exit(1);
    }

  for ( i=0; i < m; i++ )
    if ( coloring[edges[i][0]] == coloring[edges[i][1]] ) {
	sprintf( ss, "illegal coloring: vertices %d and %d are adjacent and colored with %d\n",
		 edges[i][0], edges[i][1], coloring[edges[i][0]] );
        write( 6, ss, strlen(ss) );
        exit(1);
    }
}


void PrintData( void ) {
  int i;

  printf( "[n=%d] %d edges: \n", n, m );
  for ( i=0; i < m; i++ ) {
    printf( "{%d,%d},", edges[i][0], edges[i][1] );
  }
  putchar( '\n' );

  printf( "coloring = \n" );
  for ( i=0; i < n; i++ )
     printf( "%d ", coloring[i] );
  putchar( '\n' );

}


main() {
  int t;
  FILE *uout = fdopen( 3, "r" );
  char *tmp;

  if ( uout == NULL ) {
    tmp = "error opening file\n";
    write( 6, tmp, strlen(tmp) );
    return 1;
  }

  if ( scanf( "%d\n", &t ) != 1 ) {
    tmp = "Can't read the number of test cases\n";
    write( 6, tmp, strlen(tmp) );
    return 1;
  }
  while ( t-- ) {
    ReadTestCase( stdin );
    ReadUserOutput( uout );
    //PrintData();
    CheckSol();
  }

  return 0;
}
