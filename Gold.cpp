#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	ofstream qout("Q.txt");

	double gold[1000],slope[1000],g1,g2,g3,g4,g5,u1,u2,u3,u4,u5,uu[20],ud[20],du[20],dd[20],
		pslope,pcurve,pweek,paverage,pw[10],pc[10],ps[10],pup,qwa,qca,qsa,qa;
	//gold[1000]�����ʷ��ۣ�g1~g5 ��һ~����Ľ��,u1~5��һ��������յ���ʷ�����ͣ�uu[i]��������i�����������ud��������i���µ���du�����µ�i�պ�������dd�����µ�i�պ�����µ���
	//pslope��pcurve,pweek,paverage.б�ʱ仯��Ӧ�ĸ��ʣ��ǵ��仯��Ӧ�ĸ��ʣ��ܶ�Ӧ���ʣ�pw��pc��ps,ʮ�����ݳ��ȶ�Ӧ�����ָ��ʡ�pup������������ʣ�qwa��qca,qsa,qa���ָ����ܺ�
	int week[1000],i,k,n,n1,n2,n3,n4,n5,j,judge,cn,uod,test;
	
	double qw[10]={-0.366667,-0.46579,-0.617754,-0.443056,-0.70097,-0.590419,-0.425736,-0.229911,-0.25366,0.0670449};
	double qc[10]={0.32669,-1.28333,-0.527654,-0.604489,-0.182687,0.0881943,0.00348207,0.268185,0.130421,0.306286};

	double qs[10]={0.276192,0.168217,0.644843,0.47593,0.638987,0.735016,0.723885,0.757311,0.715753,0.693886};


	double qweek=-0.126771;
	double qcurve=-0.193175;
	double qslope=0.743067;

	uod=0;

    n=0;

	/******************************************************/
	ifstream fin("000930.txt");  //�������ļ�
	////////////////////��ȡ������ʷ���� �ܡ���ۡ����///////////////////////////
	for (i=0;i<1000;i++)
	{
		fin >> week[i] >> gold[i] >> j; //���ļ���˳���ȡ�������ݵ�week gold j �� fin
		if(week[i]==0)			//�ж��Ƿ��ȡ����������
		{
			n=i;
			i=1000;
		}
	}


	cout << "pp" << n << "PP" << endl;  //������ݿ��С

	qwa=qca=qsa=qa=0;  //��ʼ��

	for(i=0;i<10;i++)
	{
		if(qw[i]>0) qwa=qwa+qw[i]; //����Ȩ��֮��
		if(qc[i]>0) qca=qca+qc[i];//��curveȨ����
		if(qs[i]>0)	qsa=qsa+qs[i];//��slopȨ����

	}
//////////////// ��Ȩ֮��/////////////
	if(qweek>0) qa=qa+qweek;
	if(qcurve>0) qa=qa+qcurve;
	if(qslope>0) qa=qa+qslope;


	int day[10]={51,101,151,201,251,301,351,401,451,n};
/****************************************/
	for(k=0;k<10;k++)
	{
		n=day[k]; //���ݳ���
		g1=g2=g3=g4=g5=u1=u2=u3=u4=u5=0;
	    n1=n2=n3=n4=n5=0;
//////////������ ����/////////////////
		for (i=0;i<n-1;i++)
		{
			slope[i]=gold[i]-gold[i+1];
		}

		/*for (i=0;i<n;i++)
		{
			cout << week[i] << "\t" << gold[i] << endl;
		}*/
//////////����Ϊ���ڣ�������� ���֮��g1 n1������ u1����������//////////////////////
		for(i=0;i<n;i++)
		{
			////////������һ ���֮��g1 n1������ u1����������/////////
			if(week[i]==1)
			{
				g1=g1+gold[i];
				n1=n1+1;
				if(i<n-1)
				{
				if(gold[i]-gold[i+1]>0) u1=u1+1;
				//cout << "##" << u1 << "##";
				}
			}

			else if(week[i]==2)
			{
				g2=g2+gold[i];
				n2=n2+1;
				if(i<n-1)
				{
					if(gold[i]-gold[i+1]>0) u2=u2+1;
				}
			}
			////////�����ܶ� ���֮��g2 n2������ u2����������/////////
			else if(week[i]==3)
			{
				g3=g3+gold[i];
				n3=n3+1;
				if(i<n-1)
				{
					if(gold[i]-gold[i+1]>0) u3=u3+1;
				}
			}
			////////�������� ���֮��g3 n3������ u3����������/////////
			else if(week[i]==4)
			{
				g4=g4+gold[i];
				n4=n4+1;
				if(i<n-1)
				{
					if(gold[i]-gold[i+1]>0) u4=u4+1;
					//cout << "***" << u4 << "***"; 
				}
			}
			////////�������� ���֮��g4 n4������ u4����������/////////
			else
			{
				g5=g5+gold[i];
				n5=n5+1;
				if(i<n-1)
				{
					if(gold[i]-gold[i+1]>0) u5=u5+1;
				}
			}

		}
	/////////////////////////////
	if(week[n-1]==1) n1=n1-1;  // ������һ������һ ��һ����������һ
	if(week[n-1]==2) n2=n2-1;
	if(week[n-1]==3) n3=n3-1;
	if(week[n-1]==4) n4=n4-1;
	if(week[n-1]==5) n5=n5-1;
	if(week[0]==1) pweek=u2/n2; //�����������һ��������ܶ��ĸ��ʣ����ǵ�������������
	if(week[0]==2) pweek=u3/n3;
	if(week[0]==3) pweek=u4/n4;
	if(week[0]==4) pweek=u5/n5;
	if(week[0]==5) pweek=u1/n1;
	
	pw[k]=pweek; //��ȡÿ����ֵ��Ӧ���ܸ���
	cout << "pweek=" << pw[k] << "\t";

////////////////////////
	for(i=0;i<10;i++)
	{
		uu[i]=ud[i]=du[i]=dd[i]=0;///�����µ�������i�պ��µ�������
	}	
	test=0;
	for(i=0;i<n-5;i++)  //n ���ݳ���
	{
		//cout << "**" << i << "**";
		if(gold[i+1]-gold[i+2]>0) //������c
		{
			cn=1;				//������/������
			judge=1;	        //�������Ǳ�־
		}
		else                     ////���콵
		{
			cn=1;				//
			judge=0;
		}

		for(j=i;j<n;j++)
		{		
			if((gold[j+1]-gold[j+2])*(gold[j+2]-gold[j+3])>0)	//������������
			{
				cn=cn+1;
			}
			else
			{
				if(judge==1)	//������������cn��
				{
					if(gold[i]-gold[i+1]>0)	 //�������Ǻ�����
					{
						uu[cn]=uu[cn]+1;
						test=test+1;
					}
					else
					{
						ud[cn]=ud[cn]+1;	//�����Ϻ���
						test=test+1;
					}
				}

				else     //�������½���cn��
				{
					if(gold[i]-gold[i+1]>0)
					{
						du[cn]=du[cn]+1;
						test=test+1;
					}
					else
					{
						dd[cn]=dd[cn]+1;
						test=test+1;
					}
				}
				j=1000;		//�������ն˺�ֹͣѭ���������жϺ�������

			} 
		}

	}
///////////�����7���� ������������ԶԴ��յ����� �����ĸ��ʣ�������///////////////////
	for(i=1;i<8;i++)
	{
		//cout <<"***"<<i<< uu[i]+ud[i];
		//cout << "***"<<i<< du[i]+dd[i]+uu[i]+ud[i]<< "***"<< endl;
		uu[i]=uu[i]/(uu[i]+ud[i]);  
		du[i]=du[i]/(du[i]+dd[i]);
		
		//cout << "u" << i << "=" << uu[i] << "\t" ;
		//cout << "d" << i << "=" << du[i] << endl ;
		//cout << "u" << i << "=" << ud[i] << "\t" ;
		//cout << "u" << i << "=" << dd[i] << endl ;
	}
	
	i=0;
	////////////�ж˽��������/////////////////////
		if(gold[i]-gold[i+1]>0)
		{
			cn=1;
			judge=1;
		}
		else
		{
			cn=1;
			judge=0;
		}
		//�������������������ó���Ӧ�������������ĸ���
		for(j=i;j<n;j++)
		{
			if((gold[j]-gold[j+1])*(gold[j+1]-gold[j+2])>0)
			{
				cn=cn+1;
			}
			else
			{
				if(judge==1)
				{
					pcurve=uu[cn];
				}

				else
				{
					pcurve=du[cn];		
				}
				j=1000;

			}
		}
	
    pc[k]=pcurve;
    cout << "pcurve=" << pc[k] << "\t"; 

	

	// k(slope) probability    slope[i]=gold[i]-gold[i+1];

	for(i=0;i<10;i++)
	{
		uu[i]=ud[i]=du[i]=dd[i]=0;
	}	

	for(i=0;i<n-3;i++)
	{
		if(slope[i+1]-slope[i+2]>0) //б������
		{
			cn=1;
			judge=1;
		}
		else
		{
			cn=1;
			judge=0;
		}

		for(j=i;j<n;j++)
		{
			if((slope[j+1]-slope[j+2])*(slope[j+2]-slope[j+3])>0)	//б�������������½�cn��
			{
				cn=cn+1;
			}
			else
			{
				if(judge==1)
				{
					if(slope[i]-slope[i+1]>0)
					{
						uu[cn]=uu[cn]+1;
					}
					else
					{
						ud[cn]=ud[cn]+1;
					}
				}

				else
				{
					if(slope[i]-slope[i+1]>0)
					{
						du[cn]=du[cn]+1;
					}
					else
					{
						dd[cn]=dd[cn]+1;
					}
				}
				j=1000;

			}
		}

	}

	/*
	cout <<"&&&"  << uu[7] << "\t" <<uu[7]+ud[7] << "&&&"<< endl;
	cout <<"&&&"  << uu[6] << "\t" <<uu[6]+ud[6] << "&&&"<< endl;
	cout <<"&&&"  << uu[5] << "\t" <<uu[5]+ud[5] << "&&&"<< endl;
	cout <<"&&&"  << uu[4] << "\t" <<uu[4]+ud[4] << "&&&"<< endl;
	cout <<"&&&"  << uu[3] << "\t" <<uu[3]+ud[3] << "&&&"<< endl;
	cout <<"&&&"  << uu[2] << "\t" <<uu[2]+ud[2] << "&&&"<< endl;
	cout <<"&&&"  << uu[1] << "\t" <<uu[1]+ud[1] << "&&&"<< endl;
	cout <<"&&&"  << du[1] << "\t" <<du[1]+dd[1] << "&&&"<< endl;
	cout <<"&&&"  << du[2] << "\t" <<du[2]+dd[2] << "&&&"<< endl;
	cout <<"&&&"  << du[3] << "\t" <<du[3]+dd[3] << "&&&"<< endl;
	cout <<"&&&"  << du[4] << "\t" <<du[4]+dd[4] << "&&&"<< endl;
	cout <<"&&&"  << du[5] << "\t" <<du[5]+dd[5] << "&&&"<< endl;
	cout <<"&&&"  << du[6] << "\t" <<du[6]+dd[6] << "&&&"<< endl;
	cout <<"&&&"  << du[7] << "\t" <<du[7]+dd[7] << "&&&"<< endl;
	*/
for(i=1;i<8;i++)
	{
		uu[i]=uu[i]/(uu[i]+ud[i]);
		du[i]=du[i]/(du[i]+dd[i]);
		//cout << "u" << i << "=" << uu[i] << "\t" ;
		//cout << "d" << i << "=" << du[i] << endl ;
		//cout << "u" << i << "=" << ud[i] << "\t" ;
		//cout << "u" << i << "=" << dd[i] << endl ;

	}
	
	i=0;

		if(slope[i]-slope[i+1]>0)
		{
			cn=1;
			judge=1;
		}
		else
		{
			cn=1;
			judge=0;
		}

		for(j=i;j<n;j++)
		{
			if((slope[j]-slope[j+1])*(slope[j+1]-slope[j+2])>0)
			{
				cn=cn+1;
			}
			else
			{
				if(judge==1)
				{
					pslope=uu[cn];
				}

				else
				{
					pslope=du[cn];
				}
				j=1000;

			}
		}
	
    ps[k]=pslope;
	
    cout << "pslope=" << ps[k] << endl; 

	
    
    fin.close();
	}
/********************************************/
	pweek=0;
	pcurve=0;
	pslope=0;
	pup=0;
	for(i=0;i<10;i++)
	{
		if(qw[i]>0) pweek=pweek+pw[i]*qw[i]/qwa;
		if(qc[i]>0) pcurve=pcurve+pc[i]*qc[i]/qca;
		if(qs[i]>0) pslope=pslope+ps[i]*qs[i]/qsa;
	}

	cout << pweek << "\t" << pcurve << "\t" << pslope << endl;

	if(qweek>0) pup=pup+pweek*qweek/qa;
	if(qcurve>0) pup=pup+pcurve*qcurve/qa;
	if(qslope>0) pup=pup+pslope*qslope/qa;



	cout << pup << endl;


	

	if(uod>0.5)
	{
		for(i=0;i<10;i++)
		{
			qw[i]=qw[i]+(pw[i]-0.5);
			qc[i]=qc[i]+(pc[i]-0.5);
			qs[i]=qs[i]+(ps[i]-0.5);
			//cout << qw[i] << "\t" << qc[i] << endl;
		}
		qweek=qweek+(pweek-0.5);
		qcurve=qcurve+(pcurve-0.5);
		qslope=qslope+(pslope-0.5);

	}
	else
	{
		for(i=0;i<10;i++)
		{
			qw[i]=qw[i]+(0.5-pw[i]);
			qc[i]=qc[i]+(0.5-pc[i]);
			qs[i]=qs[i]+(0.5-ps[i]);
			//cout << qw[i] << "\t" << qc[i] << endl;
		}
		qweek=qweek+(0.5-pweek);
		qcurve=qcurve+(0.5-pcurve);
		qslope=qslope+(0.5-pslope);
	}


	for(i=0;i<10;i++)
	{
		qout << qw[i] << ",";
	}
	qout << endl;
	for(i=0;i<10;i++)
	{
		qout << qc[i] << ",";
	}
	qout << endl;
	for(i=0;i<10;i++)
	{
		qout << qs[i] << ",";
	}
	qout << endl;
	qout << qweek << endl;
	qout << qcurve << endl;
	qout << qslope;



	if(week[n-1]==1) n1=n1+1;
	if(week[n-1]==2) n2=n2+1;
	if(week[n-1]==3) n3=n3+1;
	if(week[n-1]==4) n4=n4+1;
	if(week[n-1]==5) n5=n5+1;



	g1=g1/n1;
	g2=g2/n2;
	g3=g3/n3;
	g4=g4/n4;
	g5=g5/n5;

	u1=(u1/n1-0.5)*100;
	u2=(u2/n2-0.5)*100;
	u3=(u3/n3-0.5)*100;
	u4=(u4/n4-0.5)*100;
	u5=(u5/n5-0.5)*100;

	cout << g1 << "\t" << u1 << "\t" << n1 << endl;
	cout << g2 << "\t" << u2 << "\t" << n2 << endl;
	cout << g3 << "\t" << u3 << "\t" << n3 << endl;
	cout << g4 << "\t" << u4 << "\t" << n4 << endl;
	cout << g5 << "\t" << u5 << "\t" << n5 << endl;
	
  qout.close();
	
	
	
}