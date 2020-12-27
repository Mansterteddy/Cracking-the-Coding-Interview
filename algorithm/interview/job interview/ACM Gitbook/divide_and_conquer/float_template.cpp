const double eps = 1e-7;

double l, r;

while(l + eps < r)
{
	double mid = (l + r) / 2.0;
	if(ok(mid))
	{
		l = mid;
	}
	else
	{
		r = mid;
	}
}