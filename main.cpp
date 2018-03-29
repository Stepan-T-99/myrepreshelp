#include <stdio.h>
#include <stdlib.h>
void header (FILE *outfile) {
FILE *source = fopen ("header.html", "r");
int c;
while ((c = fgetc(source)) != EOF) {
	fputc (c, outfile);
}
}

void body (FILE *outfile, int board[8][8]) {
fprintf (outfile, "<body>\n\t<table class=\"chessboard\">\n\t\t");
for (int i = 0; i<8; i++)
{
	for (int j = 0; j < 8; j++)
	{
		if (j==0) fprintf (outfile, "<tr>");
		if (board[i][j]==0) fprintf (outfile, "<td></td>\n");
		else {
		fprintf (outfile, "<td><span class=\"");
		switch (board[i][j]) {
		case 762: fprintf (outfile, "black rook"); break;
		case 782: fprintf (outfile, "black knight"); break;
		case 662: fprintf (outfile, "black bishop"); break;
		case 822: fprintf (outfile, "black king"); break;
		case 752: fprintf (outfile, "black queen"); break;
		case 002: fprintf (outfile, "black pawn"); break;
		case 761: fprintf (outfile, "white rook"); break;
		case 781: fprintf (outfile, "white knight"); break;
		case 661: fprintf (outfile, "white bishop"); break;
		case 811: fprintf (outfile, "white king"); break;
		case 751: fprintf (outfile, "white queen"); break;
		case 001: fprintf (outfile, "white pawn"); break;
		}
		fprintf (outfile, "\"></span></td>\n");
		}
		if (j==7) fprintf (outfile, "</tr>");
	}
}
	fprintf (outfile, "</table></body></html>");
}
int main (){
FILE *index = fopen ("index.html", "w");
if (index==NULL) {printf ("error opening file");}
int chessboard[8][8] = {{762, 782, 662, 822, 752, 662, 782, 762},
		   {002, 002, 002, 002, 002, 002, 002, 002},
		   {0,   0,   0,   0,   0,   0,   0,   0},
		   {0, 0, 0, 0, 0, 0, 0, 0},
		   {0, 0, 0, 0, 0, 0, 0, 0},
		   {0, 0, 0, 0, 0, 0, 0, 0},
		   {001, 001, 001, 001, 001, 001, 001, 001},
		   {761, 781, 661, 751, 811, 661, 781, 761}};
		header (index);
		body (index, chessboard);			
}
