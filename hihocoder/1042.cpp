/*
正面很难做的话，就应该考虑从其他方面做。
判断水池的顶点，有多少个在矩形框内。
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, L;
int l, r, t, b;

int run_horse(int pl, int pr, int pt, int pb)
{
	int ll = max(l, pl);
	int rr = min(r, pr);
	int tt = max(t, pt);
	int bb = min(b, pb);

	if(ll >= rr || tt >= bb)
	{
		return (pr - pl) * (pb - pt);
	}

	int inside = 0;
	if(ll > pl && ll < pr && tt > pt && tt < pb)
		inside++;
	if(rr > pl && rr < pr && tt > pt && tt < pb)
		inside++;
	if(ll > pl && ll < pr && bb > pt && bb < pb)
		inside++;
	if(rr > pl && rr < pr && bb > pt && bb < pb)
		inside++;

	if(inside == 1 || inside == 4)
		return (pr - pl) * (pb - pt) - (rr - ll) * (bb - tt);
	else 
		return 0;

}

int main()
{
	int res = 0;

	cin>>n>>m>>L>>l>>r>>t>>b;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int w = 1;
			int h = (L - 2 * w) / 2;

			while(w > 0 && h > 0)
			{
				res = max(res, run_horse(j, min(m, j + w), i, min(n, i + h)));
				w++;
				h = (L - 2 * w) / 2;
			}
		}
	}

	cout<<res<<endl;

	return 0;
}