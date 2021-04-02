#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;

//전남이와 각 친구의 각 라운드 가위바위보 결과 알려주는 함수 
int EachScore(char c1, char c2)
{
	//전남이와 모양이 같으면 비긴 것이므로 바로 1 리턴 
	if (c1 == c2) 
		return 1;

	//비기지 않았을 때 전남이가 가위를 냈을 경우 
	else if (c1 == 'S')
	{
		//친구가 바위를 낸 경우 졌으므로 0 리턴 
		if (c2 == 'R')
			return 0;
		//그렇지 않은 경우 친구는 보자기, 이겼으므로 2 리턴 
		else
			return 2;
	}

	//비기지 않았을 때 전남이가 바위를 냈을 경우 
	else if (c1 == 'R')
	{
		//친구가 가위를 낸 경우 이겼으므로 2 리턴 
		if (c2 == 'S')
			return 2;
		//그렇지 않은 경우 친구는 보자기, 졌으므로 0 리턴 
		else
			return 0;
	}
	//비기지 않았을 때 전남이가 보자기를 냈을 경우 
	else
	{
		//친구가 가위를 낸 경우 졌으므로 0 리턴 
		if (c2 == 'S')
			return 0;
		//그렇지 않은 경우 친구는 바위, 이겼으므로 2 리턴 
		else
			return 2;
	}
}

//전남이가 얻는 총 점수 알려주는 함수 
int AllScore(string chonnam, string friend_data[], int n, int m)
{
	int score = 0;  //전남이가 얻는 총 점수 초기화 

	//각 라운드마다
	for (int i = 0; i < n; i++)
	{
		//각 라운드의 친구들마다
		for (int j = 0; j < m; j++)
		{
			char c1 = chonnam[i];         //해당 라운드 전남이 모양을 char타입에 저장
			char c2 = friend_data[j][i];  //해당 라운드 친구[j] 모양을 char타입에 저장

			//EachScore함수를 통해 각 라운드 각 친구들마다 나온 결과값을 score에 더함 
			score += EachScore(c1, c2);
		}
	}
	return score;   //총 점수 리턴 
}

//전남이가 얼마나 최대로 얻을 수 있는지 알아보는 함수 
int MaximumScore(string friend_data[], int n, int m) 
{
	int maximum_score = 0; //전남이가 얻을 수 있는 최고 점수 초기화 
	//각 라운드마다
	for (int i = 0; i < n; i++)
	{
		int temp = 0;      //라운드별 임시 최고 점수 초기화
		int score_R = 0;   //전남이가 바위일 때 점수 초기화
		int score_S = 0;   //전남이가 가위일 때 점수 초기화
		int score_P = 0;   //전남이가 보자기일 때 점수 초기화 

		//각 라운드의 친구들마다
		for (int j = 0; j < m; j++)
		{
			char c2 = friend_data[j][i];      //해당 라운드 친구[j] 모양을 char타입에 저장
			score_R += EachScore('R', c2);    //해당 라운드 전남이가 바위를 낼 경우 점수 합산 
			score_S += EachScore('S', c2);    //해당 라운드 전남이가 가위를 낼 경우 점수 합산 
			score_P += EachScore('P', c2);    //해당 라운드 전남이가 보자기를 낼 경우 점수 합산
		}
		temp = max( max(score_R, score_S), score_P ); //max함수를 이용하여 해당 라운드에서 낼 수 있는 최고 점수 저장
		maximum_score += temp; //해당 라운드에서 낼 수 있는 최고 점수 합산 
	}

	return maximum_score;  //최고 점수 리턴 
}

int main()
{
	int n, m;             //n=라운드 수, m=친구 수
	string chonnam;       //전남이가 내는 모양
	string* friend_data;  //친구들이 내는 모양

	cin >> n;             //라운드 수 입력 받음 
	cin >> chonnam;       //전남이가 각 라운드에 낸 모양 입력받음
	cin >> m;             //친구 수 입력 받음 

	friend_data = new string[m];  //string 타입 배열 동적 생성

	//반복문을 통해 각 친구들이 낸 모양 입력받음 
	for (int i = 0; i < m; i++)
	{
		cin >> friend_data[i];    
	}
	
	clock_t start = clock(); //입력 이후부터 시작 시간 저장 

	int score = AllScore(chonnam, friend_data, n, m);      //전남이 총 점수 저장 
	int maximum_score = MaximumScore(friend_data, n, m);   //전남이가 얻을 수 있는 최고 점수 저장

	cout << score << endl;             //전남이 총 점수 출력 
	cout << maximum_score << endl;     //전남이가 얻을 수 있는 최고 점수 출력 

	clock_t end = clock();  //코드가 끝난 시간 저장 
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;   //실행시간 출력 

	delete[] friend_data;   //동적배열 메모리 반환 
	return 0;
}
