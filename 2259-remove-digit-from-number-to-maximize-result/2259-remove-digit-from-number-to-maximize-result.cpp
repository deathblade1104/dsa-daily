class Solution {
public:
    string removeDigit(string number, char digit) {
        
        string a = "";
        
        for(int i=0;i<number.size();i++)
            a+='0';
                
        for(int i=0;i<number.size();i++)
        {
           if(number[i]==digit)
           {
               string temp=number.substr(0,i) + number.substr(i+1);
               
               if(temp>a)
                   a=temp;
           }
        }
        
        return a;
        
    }
};