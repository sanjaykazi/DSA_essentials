vector<string> generate(int N)
{
	// Your code here
	vector<string> v;
	queue<string> q;
	q.push("1");
	while(N--){
	    string a= q.front();
	    q.pop();
	    string b = a;
	    v.push_back(a);
	    q.push(a.append("0"));
	    q.push(b.append("1"));
	}
	return v;
}
