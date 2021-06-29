#include <bits/stdc++.h>
#define lo long long int
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'performOperations' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER_ARRAY op
 */

vector<long> performOperations(int N, vector<int> op) {
    cout<<" in the main fucntion"<<endl;
    map<lo,lo>m;
    lo M = op.size();
    for(lo i=1;i<=N;i++)m[i] = 1;
    lo first = 1, last = N;
    lo sum = N*(N+1)/2;
    vector<long>ans;
    for(lo i=0;i<M;i++){
        if(m[op[i]]){
            swap(first,last);
        }
        else{
            m.erase(last);
            sum-=last;
            sum+=op[i];
            m[op[i]] = 1;
            last = op[i];
        }
        ans.push_back(sum);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string M_temp;
    getline(cin, M_temp);

    int M = stoi(ltrim(rtrim(M_temp)));

    string op_temp_temp;
    getline(cin, op_temp_temp);

    vector<string> op_temp = split(rtrim(op_temp_temp));

    vector<int> op(M);

    for (int i = 0; i < M; i++) {
        int op_item = stoi(op_temp[i]);

        op[i] = op_item;
    }
    cout<<" befiore the perform operation"<<endl;
    vector<long> result = performOperations(N, op);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "&#039;\n&#039;";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
