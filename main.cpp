# include <bits/stdc++.h>
# include <windows.h>
# define R register int
# define r(a,b) rand()%((b)-(a)+1)+(a)

using namespace std;

const int Max_R=20;
const int Max_C=30;
int now_x,now_y,s_len,bie_cnt,times,beat_bie_cnt,limit_bie;
int loli_cnt;
char cr[100][100],st[100];
string saying,bie[100],loli[100];

void get_map()
{
	freopen("map.in","r",stdin);
    for (R i=1;i<=Max_R;++i)
        scanf("%s",cr[i]+1);
	freopen("CON","r",stdin);
}

void write_map()
{
    for (R i=1;i<=Max_R;++i)
    {
        for (R j=1;j<=Max_C;++j)
        {
            if(i==now_x&&j==now_y) putchar('@');
            else if(cr[i][j]=='$') putchar(' ');
            else if(cr[i][j]=='B') printf("B"); 
            else printf("%c",cr[i][j]);
        }
        printf("\n");
    }
}

void get_bieyu()
{
	freopen("bieyu.in","r",stdin);
	scanf("%d",&bie_cnt);
    for (R i=1;i<=bie_cnt;++i)
		cin>>bie[i];
	freopen("CON","r",stdin);
}

void get_loli()
{
	freopen("loli.in","r",stdin);
	scanf("%d",&loli_cnt);
    for (R i=1;i<=loli_cnt;++i)
		cin>>loli[i];
	freopen("CON","r",stdin);
}

void get_xy (int &x,int &y)
{
	x=r(2,Max_R-1); y=r(2,Max_C-1);
	while((x==now_x&&y==now_y)||(x==10&&y==10))
		x=r(2,Max_R-1),y=r(2,Max_C-1);
}

void make_new_bie()
{
	if(beat_bie_cnt!=limit_bie)
	{
		cout<<"您还没有打完现有的这只鳖呢~"<<endl;
		Sleep(2000);
		return;
	}
//	limit_bie=r(3,5);
	limit_bie=1;
	int x,y; get_xy(x,y);
	cr[x][y]='B';
	beat_bie_cnt=0;
	cout<<"您创造了一只新的鳖，开始快乐地打鳖吧！"<<endl; 
	Sleep(2000);
}

void move()
{
	if(cr[ now_x ][ now_y ]=='B')
	{
		cr[ now_x ][ now_y ]='$';
		int r=r(1,bie_cnt-1);
		if(beat_bie_cnt==limit_bie) r=bie_cnt;
		saying=bie[r];
		cout<<saying<<endl<<endl;
		if(r==bie_cnt) system("bie_1.jpg");
		Sleep(2000);
		if(beat_bie_cnt<limit_bie)
		{
			int x,y; get_xy(x,y);
			cr[x][y]='B';
			beat_bie_cnt++;
		}
	}
	else
	{
		int p=r(1,10);
		if(p==1)
		{
			get_loli();
			int r=r(1,loli_cnt);
			cout<<loli[r]<<endl;
			cout<<"路遇loli，您只好回到座位上学习。"<<endl;
			Sleep(2000);
			now_x=now_y=10;
		}
	}
}

int main()
{
    now_x=10,now_y=10;
    get_map();
    write_map();
    get_bieyu();
    get_loli();
    while(1)
    {
    	int x=0,y=0;
    	scanf("%s",st+1);
		if(st[1]=='w'||st[1]=='a'||st[1]=='s'||st[1]=='d') 
			scanf("%d",&times);
    	if(st[1]=='w') x=now_x-times,y=now_y;
		if(st[1]=='a') x=now_x,y=now_y-times;
		if(st[1]=='s') x=now_x+times,y=now_y;
		if(st[1]=='d') x=now_x,y=now_y+times;
		if(st[1]=='b'&&st[2]=='i'&&st[3]=='e') make_new_bie();
		if(1<x&&x<Max_R&&1<y&&y<Max_C)
			now_x=x,now_y=y,move();
		write_map();
	}
    return 0;
}
