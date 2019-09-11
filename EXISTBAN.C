/*
int exist_band0(f,a,n) float f;/* odleglosc prazka*/
		      band *a;/* array of band  */
	       unsigned int n;/* size of array */
{
int i;
for(i=0;i<n;i++)
	{
	if(a[i].met<0) continue;// skip killed bands
	if((a[i].kbz-epsilon<f)&&(f<a[i].kbz+epsilon))
		return 1;
	}
return 0;
}*/
/*
int exist_band1(f,a,n) float f;/* odleglosc prazka*/
		      band *a;/* array of band  */
	       unsigned int n;/* size of array */
{
int i;
float test;
for(i=0;i<n;i++)
	{
	if(a[i].met<0) continue;// skip killed bands
/* UWZGLEDNIENIE KROCZACEGO EPSILONA */
	if(AppType)
	  {
	  if(
	     ( (test=aproxymation(a[i].met-epsilon))>f )&&
	     ( f>aproxymation(a[i].met+epsilon) )
	    ) return 1;/* Aproksymacje powinny spelniac warunek
			    y=f(x) jest funkcja malejaca */
	test=0;
	  }
	  else
	  {
	  if(
	     (a[i].kbz-epsilon<f)&&(f<a[i].kbz+epsilon)
	    ) return 1;/* Przy braku aproksymacji pola kbz
			  i met sa rowne i  y=f(x) jest
			  rosnace */
	  }
	}
return 0;
}
*/