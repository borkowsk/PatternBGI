/* header funkcji pobierania lancucha w trybie graficznym */
/* funkcja wspolpracuje z bibliteka graficzna TURB0 C */

extern int READ_BACKGROUND;
char far* grreadstr(
		char far* dest,
		unsigned bufsiz,
		char far* zacheta,
		int x1,
		int y1,
		int szer_zn,
		int color);