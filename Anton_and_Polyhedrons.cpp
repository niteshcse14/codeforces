#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	string str;
	long long int sum = 0;
	for(int i = 0; i < N; i++)
	{
		cin>>str;
		if(str == "Tetrahedron")
		{
			sum += 4;
		}
		else if(str == "Cube")
		{
			sum += 6;
		}
		else if(str == "Octahedron")
		{
			sum += 8;
		}
		else if(str == "Dodecahedron")
		{
			sum += 12;
		}
		else if(str == "Icosahedron")
		{
			sum += 20;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
//Anton_and_Polyhedrons.cpp