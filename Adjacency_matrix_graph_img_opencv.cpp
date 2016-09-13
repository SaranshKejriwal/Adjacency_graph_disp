#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<conio.h>

using namespace std;
using namespace cv;

int main()

{
	Mat img(600,600,CV_8UC3);
	img.setTo(Scalar(0,150,0));
	int i=0,j=0;
	int x[10],y[10];
	short int isConn[10][10];
	vector<Point>nodes;
	//generate a random adjacency matrix
	for(i=0;i<10;i++)
	{
		x[i]=30+rand() / (RAND_MAX / (520 - 0 + 1) + 1);
		y[i]=30+rand() / (RAND_MAX / (520 - 0 + 1) + 1);//gives random points between (30,30) and (550,550);
		nodes.push_back(Point(x[i],y[i]));
		cout<<nodes[i]<<"\n";
		for(j=0;j<10;j++)
		{
			//if(isConn[i][j]!=0 || isConn[i][j]!=1)
			{
				isConn[i][j]=rand() / (RAND_MAX / (1 - 0 + 1) + 1);//binary adjacency matrix
				isConn[j][i]=isConn[i][j];//for undirected graphs; comment out for directed graphs
			}
			
			cout<<"isConn["<<i<<"]["<<j<<"] is "<<isConn[i][j]<<"\n";
		}
	}
	

	for(;;)
	{
		
		//circle(img,Point(60,300),5,Scalar(0,255,200),1);
		for(i=0;i<10;i++)
		{
		circle(img,Point(x[i],y[i]),5,Scalar(0,255,200),2);
		char no[10];
		sprintf(no,"node %d",i);
		putText(img,no,nodes[i],FONT_HERSHEY_DUPLEX,0.5,Scalar(0,0,0),1);
		for(j=0;j<10;j++)
			{
				if(int(isConn[i][j])==1 && int(isConn[j][i])==1)
				{
					line(img,nodes[i],nodes[j],Scalar(0,150,200),1);
					//cout<<"connected "<<i<<" "<<j<<" \n";
				}
			}
		}
		imshow("repr",img);
		
		waitKey(10);
	}
	getch();
	return 1;
}
