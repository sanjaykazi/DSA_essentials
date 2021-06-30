## Queue

###queue using stack

void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code
        if(s1.empty() && s2.empty()) return -1;
        else if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        }
        int y = s2.top();
        s2.pop();
        return y;
}
