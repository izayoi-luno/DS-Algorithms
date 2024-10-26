/*
Here is the second scenario of using stack to solve problems
ここからは二番目の問題とスタックの使用例である
*/
/*
Check for balanced parentheses
括弧のバランスが取れたかどうかを確認
*/
/*
Why stack? - "[(])" is not considered as balanced - the balance should be [()] which means "Last input parentheses first balanced" -> LIFO
どうしてスタック？｜たとえば「[(])」はバランスが取れたとは考えられない｜バランスを取れたというものが「[()]」のような構造で｜「最後に入力先にバランスを取られる」＞後入れ先出し
*/
/*
Solution:
1. scan from left to right
2. if opening symbol add it to a list -> push
3. if closing symbol check with the type of symbol -> remove the last added symbol from the list -> pop
4. should end with an empty list
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
 
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !ArePair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(AreParanthesesBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}