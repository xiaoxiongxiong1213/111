#include <cstdio>
using namespace std;

void space(int x)
{
	for (int i = 0; i< x; i++)
		printf("  ");
}

void readJSON()
{
	int dep = 0;
	char ch;
	bool slash = 0;	//转义字符，前一个字符是否为反斜杠 
	while (scanf("%c", &ch) != EOF)
	{
		switch (ch)
		{
			case '}':
			{
				if (!slash)
				{
					printf("}\n");
					space(dep);
				}
				else
				{
					printf("%c", ch);
					slash = 0;
				}
				break;
			}
			case '[':
			{
				if (!slash)
				{
					printf("arr[\n");
					space(++dep);
				}
				else
				{
					printf("%c", ch);
					slash = 0;
				}
				break;
			}
			case ']':
			{
				if (!slash)
				{
					printf("]arr\n");
					space(--dep);
				}
				else
				{
					printf("%c", ch);
					slash = 0;
				}
				break;
			}
			case ',':
			{
				if (!slash)
				{
					printf(",\n");
					space(dep);
				}
				else
				{
					printf("%c", ch);
					slash = 0;
				}
				break;
			}
			case '\\':
			{
				if (!slash)
					slash = 1;
				else slash = 0;
				printf("%c", ch);
				break;
			}
			default:
			{
				printf("%c", ch);
				break;
			}
		}
	}
}

int main()
{ 
	readJSON();
	return 0;
}
