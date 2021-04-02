#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;

//�����̿� �� ģ���� �� ���� ���������� ��� �˷��ִ� �Լ� 
int EachScore(char c1, char c2)
{
	//�����̿� ����� ������ ��� ���̹Ƿ� �ٷ� 1 ���� 
	if (c1 == c2) 
		return 1;

	//����� �ʾ��� �� �����̰� ������ ���� ��� 
	else if (c1 == 'S')
	{
		//ģ���� ������ �� ��� �����Ƿ� 0 ���� 
		if (c2 == 'R')
			return 0;
		//�׷��� ���� ��� ģ���� ���ڱ�, �̰����Ƿ� 2 ���� 
		else
			return 2;
	}

	//����� �ʾ��� �� �����̰� ������ ���� ��� 
	else if (c1 == 'R')
	{
		//ģ���� ������ �� ��� �̰����Ƿ� 2 ���� 
		if (c2 == 'S')
			return 2;
		//�׷��� ���� ��� ģ���� ���ڱ�, �����Ƿ� 0 ���� 
		else
			return 0;
	}
	//����� �ʾ��� �� �����̰� ���ڱ⸦ ���� ��� 
	else
	{
		//ģ���� ������ �� ��� �����Ƿ� 0 ���� 
		if (c2 == 'S')
			return 0;
		//�׷��� ���� ��� ģ���� ����, �̰����Ƿ� 2 ���� 
		else
			return 2;
	}
}

//�����̰� ��� �� ���� �˷��ִ� �Լ� 
int AllScore(string chonnam, string friend_data[], int n, int m)
{
	int score = 0;  //�����̰� ��� �� ���� �ʱ�ȭ 

	//�� ���帶��
	for (int i = 0; i < n; i++)
	{
		//�� ������ ģ���鸶��
		for (int j = 0; j < m; j++)
		{
			char c1 = chonnam[i];         //�ش� ���� ������ ����� charŸ�Կ� ����
			char c2 = friend_data[j][i];  //�ش� ���� ģ��[j] ����� charŸ�Կ� ����

			//EachScore�Լ��� ���� �� ���� �� ģ���鸶�� ���� ������� score�� ���� 
			score += EachScore(c1, c2);
		}
	}
	return score;   //�� ���� ���� 
}

//�����̰� �󸶳� �ִ�� ���� �� �ִ��� �˾ƺ��� �Լ� 
int MaximumScore(string friend_data[], int n, int m) 
{
	int maximum_score = 0; //�����̰� ���� �� �ִ� �ְ� ���� �ʱ�ȭ 
	//�� ���帶��
	for (int i = 0; i < n; i++)
	{
		int temp = 0;      //���庰 �ӽ� �ְ� ���� �ʱ�ȭ
		int score_R = 0;   //�����̰� ������ �� ���� �ʱ�ȭ
		int score_S = 0;   //�����̰� ������ �� ���� �ʱ�ȭ
		int score_P = 0;   //�����̰� ���ڱ��� �� ���� �ʱ�ȭ 

		//�� ������ ģ���鸶��
		for (int j = 0; j < m; j++)
		{
			char c2 = friend_data[j][i];      //�ش� ���� ģ��[j] ����� charŸ�Կ� ����
			score_R += EachScore('R', c2);    //�ش� ���� �����̰� ������ �� ��� ���� �ջ� 
			score_S += EachScore('S', c2);    //�ش� ���� �����̰� ������ �� ��� ���� �ջ� 
			score_P += EachScore('P', c2);    //�ش� ���� �����̰� ���ڱ⸦ �� ��� ���� �ջ�
		}
		temp = max( max(score_R, score_S), score_P ); //max�Լ��� �̿��Ͽ� �ش� ���忡�� �� �� �ִ� �ְ� ���� ����
		maximum_score += temp; //�ش� ���忡�� �� �� �ִ� �ְ� ���� �ջ� 
	}

	return maximum_score;  //�ְ� ���� ���� 
}

int main()
{
	int n, m;             //n=���� ��, m=ģ�� ��
	string chonnam;       //�����̰� ���� ���
	string* friend_data;  //ģ������ ���� ���

	cin >> n;             //���� �� �Է� ���� 
	cin >> chonnam;       //�����̰� �� ���忡 �� ��� �Է¹���
	cin >> m;             //ģ�� �� �Է� ���� 

	friend_data = new string[m];  //string Ÿ�� �迭 ���� ����

	//�ݺ����� ���� �� ģ������ �� ��� �Է¹��� 
	for (int i = 0; i < m; i++)
	{
		cin >> friend_data[i];    
	}
	
	clock_t start = clock(); //�Է� ���ĺ��� ���� �ð� ���� 

	int score = AllScore(chonnam, friend_data, n, m);      //������ �� ���� ���� 
	int maximum_score = MaximumScore(friend_data, n, m);   //�����̰� ���� �� �ִ� �ְ� ���� ����

	cout << score << endl;             //������ �� ���� ��� 
	cout << maximum_score << endl;     //�����̰� ���� �� �ִ� �ְ� ���� ��� 

	clock_t end = clock();  //�ڵ尡 ���� �ð� ���� 
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;   //����ð� ��� 

	delete[] friend_data;   //�����迭 �޸� ��ȯ 
	return 0;
}
