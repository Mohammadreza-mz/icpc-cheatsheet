// Z[i] => max len perfixi az s k az khuneye i e S shoru mishe

int L = 0, R = 0;
n=s.size();
for (int i = 1; i < n; i++) 
{
	if (i > R) {
		L = R = i;
		while (R < n && s[R-L] == s[R]) R++;
		z[i] = R-L; R--;
	}	 
	else
	{
		int k = i-L;
		if (z[k] < R-i+1) z[i] = z[k];
		else 
		{
			L = i;
			while (R < n && s[R-L] == s[R]) R++;
			z[i] = R-L; R--;
		}
	}
}