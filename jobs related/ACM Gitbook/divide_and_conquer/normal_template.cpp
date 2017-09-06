int l, r, res;

while(l <= r)
{
	int mid = (l + r) / 2;
	if(ok(mid))
	{
		res = mid;
		r = mid - 1;
	}
	else
		l = mid + 1;
}

