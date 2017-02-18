#include<stdio.h>
#include<string.h>

int call(char a[], char b[])
{
	int i=0, j=0, na=strlen(a), nb=strlen(b), count=0, start = 0;
	while(i<na && j<nb)
	{
		if(a[i] == b[j])
		{
			i++;
			j++;
			count++;
		}
		else
		{
			if(count == 0)
			{
				i++;
			}
			else
			{
				i++;
				i-=count;
				j=0;
				count=0;
			}
		}
	}
	return count;
}
int func()
{

	if(max==n1)
	{
		for(i=0;i<n2;i++)
		{
			ans[i]=s2[i];
			final[i]=s2[i];
		}
		final[i+1]='\0';
	}
	else if(max==n2)
	{
		for(i=0;i<n1;i++)
		{
			ans[i]=s1[i];
			final[i]=s1[i];
		}
		final[i+1]='\0';
	}
	else
	{
		for(i=0;i<n1+n2;i++)
		{
			if(i<n1)
			{
				ans[i]=s1[i];
			}
			else
			{
				ans[i]=s2[i-n1];
			}
		}
		int tem=0;
		for(i=n1-1;i>=0;i--)
		{
			if(tem==max)
			{
				break;
			}
			else
			{
				ans[i]='*';
				tem++;
			}
		}
		tem=0;
		for(i=0;i<n1+n2;i++)
		{
			if(ans[i]!='*')
			{
				final[tem]=ans[i];
				tem++;
			}
		}
		final[tem+1]='\0';
	}
	ans[n1+n2]='\0';
	x=call(final, s3);
	y=call(s3,final);
	if(x>y)
		res=strlen(final)+n3-x;
	else
		res=strlen(final)+n3-y;
}
}
int main(void)
{
	char s1[100005], s2[100005], s3[100005], ans[300015], final[300015];
	scanf("%s %s %s", s1, s2, s3);
	int i, j, n1=strlen(s1), n2=strlen(s2), n3=strlen(s3), arr[6], max=-1, pos, x, y, res;
	arr[0]=call(s1,s2);
	arr[1]=call(s2,s1);
	arr[2]=call(s2,s3);
	arr[3]=call(s3,s2);
	arr[4]=call(s1,s3);
	arr[5]=call(s3,s1);
	for(i=0;i<6;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			pos=i;
		}
	}

	if(pos==0)
	{
		if(max==n1)
		{
			for(i=0;i<n2;i++)
			{
				ans[i]=s2[i];
				final[i]=s2[i];
			}
			final[i+1]='\0';
		}
		else if(max==n2)
		{
			for(i=0;i<n1;i++)
			{
				ans[i]=s1[i];
				final[i]=s1[i];
			}
			final[i+1]='\0';
		}
		else
		{
			for(i=0;i<n1+n2;i++)
			{
				if(i<n1)
				{
					ans[i]=s1[i];
				}
				else
				{
					ans[i]=s2[i-n1];
				}
			}
			int tem=0;
			for(i=n1-1;i>=0;i--)
			{
				if(tem==max)
				{
					break;
				}
				else
				{
					ans[i]='*';
					tem++;
				}
			}
			tem=0;
			for(i=0;i<n1+n2;i++)
			{
				if(ans[i]!='*')
				{
					final[tem]=ans[i];
					tem++;
				}
			}
			final[tem+1]='\0';
		}
		ans[n1+n2]='\0';
		x=call(final, s3);
		y=call(s3,final);
		if(x>y)
			res=strlen(final)+n3-x;
		else
			res=strlen(final)+n3-y;
	}

	else if(pos==1)
	{
		// means s2,s1
		if(max==n1)
		{
			for(i=0;i<n2;i++)
			{
				ans[i]=s2[i];
				final[i]=s2[i];
			}
			final[i+1]='\0';
		}
		else if(max==n2)
		{
			for(i=0;i<n1;i++)
			{
				ans[i]=s1[i];
				final[i]=s1[i];
			}
			final[i+1]='\0';
		}
		else
		{
			for(i=0;i<n1+n2;i++)
			{
				if(i<n2)
				{
					ans[i]=s2[i];
				}
				else
				{
					ans[i]=s1[i-n2];
				}
			}
			int tem=0;
			for(i=n2-1;i>=0;i--)
			{
				if(tem==max)
				{
					break;
				}
				else
				{
					ans[i]='*';
					tem++;
				}
			}
			tem=0;
			for(i=0;i<n1+n2;i++)
			{
				if(ans[i]!='*')
				{
					final[tem]=ans[i];
					tem++;
				}
			}
			final[tem+1]='\0';
		}
		ans[n1+n2]='\0';
		x=call(final, s3);
		y=call(s3,final);
		if(x>y)
			res=strlen(final)+n3-x;
		else
			res=strlen(final)+n3-y;
	}

	else if(pos==2)
	{
		// means s2,s3
		if(max==n2)
		{
			for(i=0;i<n3;i++)
			{
				ans[i]=s3[i];
				final[i]=s3[i];
			}
			final[i+1]='\0';
		}
		else if(max==n3)
		{
			for(i=0;i<n2;i++)
			{
				ans[i]=s2[i];
				final[i]=s2[i];
			}
			final[i+1]='\0';
		}
		else
		{
			for(i=0;i<n2+n3;i++)
			{
				if(i<n2)
				{
					ans[i]=s2[i];
				}
				else
				{
					ans[i]=s3[i-n2];
				}
			}
			int tem=0;
			for(i=n2-1;i>=0;i--)
			{
				if(tem==max)
				{
					break;
				}
				else
				{
					ans[i]='*';
					tem++;
				}
			}
			tem=0;
			for(i=0;i<n2+n3;i++)
			{
				if(ans[i]!='*')
				{
					final[tem]=ans[i];
					tem++;
				}
			}
			final[tem+1]='\0';
		}
		ans[n2+n3]='\0';
		x=call(final, s1);
		y=call(s1,final);
		if(x>y)
			res=strlen(final)+n1-x;
		else
			res=strlen(final)+n1-y;
	}

	else if(pos==3)
	{
		// means s3,s2
		if(max==n3)
		{
			for(i=0;i<n2;i++)
			{
				ans[i]=s2[i];
				final[i]=s2[i];
			}
			final[i+1]='\0';
		}
		else if(max==n2)
		{
			for(i=0;i<n3;i++)
			{
				ans[i]=s3[i];
				final[i]=s3[i];
			}
			final[i+1]='\0';
		}
		else
		{
			for(i=0;i<n2+n3;i++)
			{
				if(i<n3)
				{
					ans[i]=s3[i];
				}
				else
				{
					ans[i]=s2[i-n3];
				}
			}
			int tem=0;
			for(i=n3-1;i>=0;i--)
			{
				if(tem==max)
				{
					break;
				}
				else
				{
					ans[i]='*';
					tem++;
				}
			}
			tem=0;
			for(i=0;i<n2+n3;i++)
			{
				if(ans[i]!='*')
				{
					final[tem]=ans[i];
					tem++;
				}
			}
			final[tem+1]='\0';
		}
		ans[n2+n3]='\0';
		x=call(final, s1);
		y=call(s1,final);
		if(x>y)
			res=strlen(final)+n1-x;
		else
			res=strlen(final)+n1-y;
	}

	else if(pos==4)
	{
		// means s1,s3
		if(max==n1)
		{
			for(i=0;i<n3;i++)
			{
				ans[i]=s3[i];
				final[i]=s3[i];
			}
			final[i+1]='\0';
		}
		else if(max==n3)
		{
			for(i=0;i<n1;i++)
			{
				ans[i]=s1[i];
				final[i]=s1[i];
			}
			final[i+1]='\0';
		}
		else
		{
			for(i=0;i<n1+n3;i++)
			{
				if(i<n1)
				{
					ans[i]=s1[i];
				}
				else
				{
					ans[i]=s3[i-n1];
				}
			}
			int tem=0;
			for(i=n1-1;i>=0;i--)
			{
				if(tem==max)
				{
					break;
				}
				else
				{
					ans[i]='*';
					tem++;
				}
			}
			tem=0;
			for(i=0;i<n1+n3;i++)
			{
				if(ans[i]!='*')
				{
					final[tem]=ans[i];
					tem++;
				}
			}
			final[tem+1]='\0';
		}
		ans[n1+n3]='\0';
		x=call(final, s2);
		y=call(s2,final);
		if(x>y)
			res=strlen(final)+n2-x;
		else
			res=strlen(final)+n2-y;
	}

	else if(pos==5)
	{
		// means s3,s1
		if(max==n1)
		{
			for(i=0;i<n3;i++)
			{
				ans[i]=s3[i];
				final[i]=s3[i];
			}
			final[i+1]='\0';
		}
		else if(max==n3)
		{
			for(i=0;i<n1;i++)
			{
				ans[i]=s1[i];
				final[i]=s1[i];
			}
			final[i+1]='\0';
		}
		else
		{
			for(i=0;i<n1+n3;i++)
			{
				if(i<n3)
				{
					ans[i]=s3[i];
				}
				else
				{
					ans[i]=s1[i-n3];
				}
			}
			int tem=0;
			for(i=n3-1;i>=0;i--)
			{
				if(tem==max)
				{
					break;
				}
				else
				{
					ans[i]='*';
					tem++;
				}
			}
			tem=0;
			for(i=0;i<n1+n3;i++)
			{
				if(ans[i]!='*')
				{
					final[tem]=ans[i];
					tem++;
				}
			}
			final[tem+1]='\0';
		}
		ans[n1+n3]='\0';
		x=call(final, s2);
		y=call(s2,final);
		if(x>y)
			res=strlen(final)+n2-x;
		else
			res=strlen(final)+n2-y;
	}
	//printf("%s\n", final);
	printf("%d\n", res);
	return(0);
}
