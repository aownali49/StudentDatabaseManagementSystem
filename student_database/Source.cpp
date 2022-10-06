#include<iostream>
#define RMAX 70
#define TM 500
#define TRUE 1
#define NAMESIZE 30
#define SUB 5
using namespace std;
class student
{
	int rno;
	char name[NAMESIZE];
	int mark[SUB], totmarks;
	float per;
	char grade;
public:
	void createdb(student ss[], int nn);
	bool checkstd(int nn, int lo, int up);
	void result(student ss[], int nn);
	void process(student ss[], int nn);
	void appenddb(student ss[], int& nn);
	int reg(student ss[], int nn, int data);
	void sort(student ss[], int nn);
	bool checkreg(int data);
	int search(student ss[], int nn, int sd);
	void deletion(student ss[], int& nn, int pp);
	void updation(student ss[], int nn, int p);
};
void student::createdb(student ss[], int nn)
{
	int ch = 1;
	int pos = 0;
	int data;
	for (int i = 0; i < nn; i++)
	{
		cout << "Enter Data for Student # " << i + 1 << endl;
		do
		{
			cout << "Enter Reg.No for Student  # " << i + 1 << "  : ";
			cin >> ss[i].rno;
			data = ss[i].rno;
			if (checkreg(data))
				ch = 0;
			else
			{
				cout << "Sorry,Enter Valid Reg.NO \n";
				cout << endl;
			}
			if (i != 0)
			{
				pos = reg(ss, i, data);
				if (pos == -1)
				{
					cout << "This Reg.No is Already Exist \n\n";
					ch = 1;
				}
			}


		} while (ch == 1);
		cin.ignore(10, '\n');
		cout << "Name : ";
		cin.get(ss[i].name, NAMESIZE);
		cin.ignore(10, '\n');
		for (int j = 0; j < SUB; j++)
		{

			do
			{
				cout << "Enter Marks of Subject  : " << j + 1 << " : ";
				cin >> ss[i].mark[j];
				cout << endl;
				if (checkstd(ss[i].mark[j], 0, 100))
					break;
				else
					cout << "Kindly , Enter Correct Marks\n\n";
			} while (TRUE);
		}
	}
	process(ss, nn);
}
void student::appenddb(student ss[], int& nn)
{
	int ch = 1;
	int pos = 0;

	cout << "Enter Data for Student # " << nn + 1 << endl;
	do
	{
		cout << "Enter Reg.No for Student  # " << nn + 1 << "  : ";
		cin >> ss[nn].rno;
		cout << endl;
		int data = ss[nn].rno;
		if (checkreg(data))
			ch = 0;
		else
		{
			cout << "Sorry,Enter Valid Reg.NO \n";
			cout << endl;
		}
		if (nn != 0)
		{
			pos = reg(ss, nn, ss[nn].rno);
			if (pos == -1)
			{
				cout << "This Reg.No is Already Exist \n\n";
				ch = 1;
			}
		}

	} while (ch == 1);
	cin.ignore(10, '\n');
	cout << "Name : ";
	cin.get(ss[nn].name, NAMESIZE);
	cin.ignore(10, '\n');
	for (int j = 0; j < SUB; j++)
	{

		do
		{
			cout << "Enter Marks of Subject  : " << j + 1 << " : ";
			cin >> ss[nn].mark[j];
			cout << endl;
			if (checkstd(ss[nn].mark[j], 0, 100))
				break;
			else
				cout << "Kindly , Enter Correct Marks\n\n";
		} while (TRUE);


	}
	nn++;
	process(ss, nn);
}
void student::result(student ss[], int nn)
{
	int ch = 1;
	int pos = 0;
	for (int i = 0; i < nn; i++)
	{
		cout << "Data for Student # " << i + 1 << endl;
		do
		{
			cout << " Reg.No for Student  # " << i + 1 << "  : ";
			cout << ss[i].rno;
			cout << endl;
			cout << "Name : ";
			cout << ss[i].name;
			cout << endl;
			cout << endl;
			for (int j = 0; j < SUB; j++)
			{
				cout << " Marks of Subject  : " << j + 1 << " : ";
				cout << ss[i].mark[j];
				cout << endl;
			}
			cout << "TOTAL MARKS : " << ss[i].totmarks << endl;
			cout << "%Age : " << ss[i].per << "%" << endl;
			cout << "Grade : " << ss[i].grade << endl;




			ch = 0;
			cout << endl;
		} while (ch == 1);
	}

}
void student::process(student ss[], int nn)
{


	for (int i = 0; i < nn; i++)
	{
		ss[i].totmarks = 0;
		for (int j = 0; j < SUB; j++)
		{
			ss[i].totmarks += ss[i].mark[j];
		}
		ss[i].per = (ss[i].totmarks * 100.0) / 500.0;
		if (ss[i].per >= 80)
			ss[i].grade = 'A';
		else if ((ss[i].per < 80) && (ss[i].per >= 70))
			ss[i].grade = 'B';
		else if ((ss[i].per < 70) && (ss[i].per >= 60))
			ss[i].grade = 'C';
		else
			ss[i].grade = 'F';
	}

}
int student::reg(student ss[], int nn, int data)
{
	int pos = 1;
	for (int i = 0; i < nn; i++)
	{
		if (ss[i].rno == data)
		{
			pos = -1;
			break;
		}
	}
	return pos;
}
bool student::checkstd(int nn, int lo, int up)
{
	if ((nn > lo) && (nn <= up))
		return true;
	else
		return false;

}
bool student::checkreg(int data)
{
	if ((data >= 1000) && (data <= 9999))
		return true;
	else
		return false;

}
int student::search(student ss[], int nn, int sd)
{
	int pos = -1;
	for (int i = 0; i < nn; i++)
	{
		if (ss[i].rno == sd)
		{
			pos = i;
			break;
		}
	}
	return pos;

}
void student::sort(student ss[], int nn)
{
	int max;
	int temp;
	for (int i = 0; i < nn; i++)
	{
		max = i;
		for (int j = i + 1; j < nn; j++)
		{
			if (ss[max].rno > ss[j].rno)
			{
				temp = ss[j].rno;
				ss[j].rno = ss[i].rno;
				ss[i].rno = temp;
				for (int k = 0; k < SUB; k++)
				{
					temp = ss[j].mark[k];
					ss[j].mark[k] = ss[i].mark[k];
					ss[i].mark[k] = temp;
				}

			}
		}
	}
	process(ss, nn);

}
void student::updation(student ss[], int nn, int p)
{
	cout << "Now Update All Information About Reg.No # " << ss[p].rno << endl << endl;
	cin.ignore(10, '\n');
	cout << "Name : ";
	cin.get(ss[p].name, NAMESIZE);
	cin.ignore(10, '\n');
	for (int j = 0; j < SUB; j++)
	{

		do
		{
			cout << "Enter Marks of Subject  : " << j + 1 << " : ";
			cin >> ss[p].mark[j];
			cout << endl;
			if (checkstd(ss[p].mark[j], 0, 100))
				break;
			else
				cout << "Kindly , Enter Correct Marks\n\n";
		} while (TRUE);
	}
	process(ss, nn);

}
void student::deletion(student ss[], int& nn, int pp)
{
	for (int i = pp; i < nn - 1; i++)
		ss[i] = ss[i + 1];
	nn--;

}
int main()
{
	student S[RMAX];
	int n = 0;
	int ch;
	int sinfo, pos;
	do {
		cout << ".................... MAIN MANU ..................\n" << endl;
		cout << "\t\t 1 ) Create DATABASE  " << endl;
		cout << "\t\t 2 ) Append New Record " << endl;
		cout << "\t\t 3 ) Search  " << endl;
		cout << "\t\t 4 ) Sort " << endl;
		cout << "\t\t 5 ) Update " << endl;
		cout << "\t\t 6 ) Delete  " << endl;
		cout << "\t\t 7 ) Display Result " << endl;
		cout << "\t\t 8 ) Exit " << endl;
		cout << endl;
		cout << "Enter Your Choice # ";
		cin >> ch;
		cout << endl;
		switch (ch)
		{
		case 1:
			do
			{
				cout << "Enter No of Student Max[70] : ";
				cin >> n;
				cout << endl;
				if (n > 0 && n != 0)
					break;
				else
					cout << "You No of Student is Invalid \n\nEnter Again\n\n";
			} while (TRUE);
			S[n].createdb(S, n);
			break;
		case 2:
			S[n].appenddb(S, n);
			break;
		case 3:
			if ((n > 0))
			{
				cout << "Enter Reg.No For Searching # ";
				cin >> sinfo;
				cout << endl;
				pos = S[n].search(S, n, sinfo);
				if (pos == -1)
					cout << "Reg.No Not Found \n\n";
				else
					cout << "Reg.No Found at position : " << pos << endl << endl;
			}
			else
				cout << "You can't Search withOut Data \n\n";
			break;
		case 4:
			if ((n > 0))
				S[n].sort(S, n);
			else
				cout << "You can't Sort withOut Data \n\n";
			break;
		case 5:
			if ((n > 0))
			{
				cout << "Enter Reg.No For Updation # ";
				cin >> sinfo;
				cout << endl;
				pos = S[n].search(S, n, sinfo);
				if (pos == -1)
					cout << "Reg.No Not Found \n\n";
				else
				{
					cout << "Reg.No Found at position : " << pos << endl << endl;
					S[n].updation(S, n, pos);
					cout << endl;
				}
			}
			else
				cout << "You can't Update withOut Data \n\n";
			break;
		case 6:
			if ((n > 0))
			{
				cout << "Enter Reg.No For Deletion # ";
				cin >> sinfo;
				cout << endl;
				pos = S[n].search(S, n, pos);
				if (pos == -1)
					cout << "Reg.No Not Found \n\n";
				else
				{
					cout << "Reg.No Found at position : " << pos << endl << endl;
					S[n].deletion(S, n, pos);
					cout << endl;
				}
			}
			else
				cout << "You can't Delete withOut Data \n\n";
			break;
		case 7:
			if ((n > 0))
				S[n].result(S, n);
			else
				cout << "No Data Found, Enter data first" << endl;
			break;

		case 8:
			exit(-1);
		default:
			cout << "Your Choice is Wrong ,Kindly Select One of the Above \n\n";
		}
	} while (TRUE);
	system("pause");
}