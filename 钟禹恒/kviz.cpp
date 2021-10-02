#include<bits/stdc++.h>
using namespace std;
char s[51];
int sl;
double wordnum;
int num;
bool flag;
void tips1()
{
	for(int i=0;i<sl;i++) 
	{
		if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
		{
		 	printf(".");
		 	wordnum++;
		}
		else printf("%c",s[i]);
	}
	printf("\n");
}
void tips2()
{
	num=(int)(wordnum/3.0+0.5);
	for(int i=0;i<sl;i++) 
	{
		if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
		{
			if(num>0)
			{
				printf("%c",s[i]);
				num--;
			}
		 	else printf(".");
		}
		else printf("%c",s[i]);
	}
	printf("\n");
}
void tips3()
{
	num=(int)(wordnum/3.0+0.5);
	for(int i=num+2;i<sl;i++) 
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		
		for(int i=0;i<sl;i++) 
		{
			if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
			{
				if(num>0)
				{
					printf("%c",s[i]);
					num--;
					continue;
				}
				if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
				{
					printf("%c",s[i]);
//					cout<<0<<endl;
					continue;
				}
			 	printf(".");
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}
	else
	{
		num=(int)(wordnum*2.0/3.0+0.5);
		for(int i=0;i<sl;i++) 
		{
			if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
			{
				if(num>0)
				{
					printf("%c",s[i]);
					num--;
				}
			 	else printf(".");
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}
}
int main()
{
	freopen("kviz.in","r",stdin);
	freopen("kviz.out","w",stdout);
	gets(s);
	sl=strlen(s);
	tips1();
	tips2();
	tips3();
	return 0;
}
