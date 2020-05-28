/*
  deskryptory:
stdin - test cases
3 - user out.
6 - error messages


sposob uzycia tego programu:
zakladamy, ze w pliku input znajduja sie dane testowe
mamy program prog.c, rozwiazujacy zadanie
aby przetestowac program:

1) kompilujemy
gcc -o prog prog.c

2) generujemy wyjscie
./prog <input >output

3) kompilujemy ten plik
gcc -o euler_judge euler_judge.c

4) sprawdzamy, czy plik wyjsciowy jest poprawny
./euler_judge <input 3<output 6>err

5) jesli wystapily bledy, to komunikaty znajduja sie w pliku err.
   jesli plik err jest pusty, to wyscie jest poprawne, albo
   nastapil blad wykonania programu euler_judge i wowczas
   takie rozwiazanie nie jest akceptowane na spoju


komunikaty bledow:
  "Cycle too short" oznacza, ze cykl zawiera zbyt malo krawedzi,

  "Wrong vertex" oznacza, ze numer wierzcholka nie jest poprawny (poza zakresem 0,...,n-1)

  "No such edge" oznacza, ze cykl zawiera krawedz, ktorej nie ma w grafie

  "There are remaining edges" cykl byl co prawda poprawny, ale nie obejmuje wszystkich krawedzi grafu

*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200


void print_g( int g[N][N], int n, int m ) {
  int u, v;
  printf( "n=%d,m=%d\n", n, m );

  for ( u=0; u < n; u++ )
    for ( v=u+1; v < n; v++ )
      if ( g[u][v] != 0 )
	printf( "{%d,%d} ", u, v );
  printf( "\n" );
}

void read_g( int g[N][N], int *n, int *m, FILE *f ) {
  int i, u, v, a, b;

  fscanf( f, "n=%d,m=%d\n", n, m );

  for ( u=0; u < *n; u++ )
    for ( v=0; v < *n; v++ )
      g[u][v] = 0;
  
  for ( i=0; i < *m; i++ ) {
    fscanf( f, "{%d,%d} ", &a, &b );
    g[a][b] = g[b][a] = 1;
  }
}


int NumOfEdges( int g[N][N], int n ) {
  int i, j, m=0;
  for ( i=0; i < n; i++ )
    for ( j=i+1; j < n; j++ )
      m += g[i][j];
  return m;
}


void CheckTestCase( FILE *fd, int g[N][N], int n, int m ) {
  int u, v, i;
  
  //m = NumOfEdges( g, n );
  if ( fscanf( fd, "%d", &u ) != 1 ) {
    write( 6, "Cycle too short\n", strlen("Cycle too short\n") );
    exit(1);
  }
  if ( u < 0 || u >= n ) {
    write( 6, "Wrong vertex\n", strlen("Wrong vertex\n") );
    exit(1);
  }

  for ( i=0; i < m; i++ ) {
    if ( fscanf( fd, "%d", &v ) != 1 ) {
      write( 6, "Cycle too short\n", strlen("Cycle too short\n") );
      exit(1);
    }

    if ( v < 0 || v >= n ) {
      write( 6, "Wrong vertex\n", strlen("Wrong vertex\n") );
      exit(1);
    }

    if ( g[u][v] != 1 ) {
      write( 6, "No such edge\n", strlen("No such edge\n") );
      exit(1);
    }
    g[u][v] = g[v][u] = 0;
    u = v;
  }

  if ( NumOfEdges( g, n ) > 0 ) {
    write( 6, "There are remaining edges\n", strlen("There are remaining edges\n") );
    exit(1);
  }

}


main() {
  int t;
  FILE *uout = fdopen( 3, "r" );
  char *tmp;

  int g[N][N], n, m;

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
    read_g( g, &n, &m, stdin );
    //print_g( g, n, m );
    CheckTestCase( uout, g, n, m );
  }

  return 0;
}
