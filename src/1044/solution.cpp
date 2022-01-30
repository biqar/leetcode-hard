//
// Created by Islam, Abdullah Al Raqibul on 01/30/22.
//

// todo: the following solution got TLE ...

class Solution {
public:
  //const long long mod = 1e9 + 9;
  const int mod = (1e7 + 7);
  const int p = 26;
  vector<int> roll;

  int searchSubstring__TLE(string &str, int len, int sz) {
    unordered_map<int, vector<int>> m;
    int base = 0;
    int po = 1;

    for(int i=0; i<len; i++) {
      base = ((base * 26) + (str[i] - 'a')) % mod;
    }

    for(int i=0; i<len; ++i) {
      po = (po * 26) % mod;
    }

    m[base].push_back(0);

    for (int i=1; i+len<=sz; i+=1) {
      base = (base * 26) - ((str[i-1] - 'a') * po) + (str[i+len-1] - 'a') + mod;
      while(base < 0) base += mod;
      base %= mod;

//             if(len == 7499 && i == 15000-2) {
//                 cout << base << " ~~ " << m[base].size() << endl;
//                 cout << "special: " << str.substr(i, len) << endl;
//             }

//             if(len == 7499 && i == (sz-len-1)) {
//                 cout << base << " ~~ " << m[base].size() << endl;
//                 cout << "special: " << str.substr(i, len) << endl;
//             }

      if (m.find(base) != m.end()) {
        string temp=str.substr(i, len);
        // if(len == 7499) cout << "tmp: " << temp << endl;
        for(int j : m[base]) {
          string curr=str.substr(j, len);
          // if(len == 7499) cout << "curr: " << curr << endl;
          if(temp == curr) return i;
        }
        // if(len == 7499) cout << endl;
      }

      m[base].push_back(i);
    }
    return -1;
  }

  bool searchSubstring(string &str, int len, int sz, string &dup) {
    unordered_map<int, vector<int>> m;
    int base = 0;
    int po = roll[len], idx;

    // note: this look was causing the TLE (last time)
    // for (int i = 0; i < len; i++) po = (po * p) % mod;

    for (int i = 0; i < sz; i++) {
      base = base*p + (str[i] - 'a' + 1);
      base %= mod;
      if (i >= len) {
        base -= po * (str[i-len] - 'a' + 1) % mod;
        if (base < 0) base += mod;
      }
      if (i >= len-1) {
        idx = i - (len-1);

        if (m.find(base) != m.end()) {
          string temp=str.substr(idx, len);
          // if(len == 7499) cout << "tmp: " << temp << endl;
          for(int j : m[base]) {
            string curr=str.substr(j, len);
            // if(len == 7499) cout << "curr: " << curr << endl;
            if(temp == curr) {
              dup = curr;
              return true;
            }
          }
          // if(len == 7499) cout << endl;
        }

        m[base].push_back(idx);
      }
    }
    return false;
  }

  string longestDupSubstring(string S) {
    // todo: why we need to set "lo = 1"???
    int sz = S.length(), lo = 1, hi = S.length(), mid, dupIdx;
    string ret = "";

    roll.resize(sz+1);
    roll[0] = 1;
    for(int i=1; i<=sz; i+=1) roll[i] = (p * roll[i-1])%mod;

    // cout << sz << endl;

    // todo: why "<="? why not "<" only?
    while(lo <= hi) {
      // cout << lo << " " << hi << endl;
      // mid = lo + (hi-lo)/2;
      string tmp = "";
      // todo: why this mid rule? why not the previous one?
      mid = (lo+hi)/2;

      // cout << "->" << mid << " " << dupIdx << endl;
      if(searchSubstring(S, mid, sz, tmp)) {
        if(tmp.length() > ret.length()) ret = tmp;
        lo = mid + 1;
      }
      else {
        hi = mid - 1;
      }
    }

    return ret;

    // cout << lo << " " << hi << endl;

//         dupIdx = searchSubstring(S, hi, sz);
//         // cout << dupIdx << endl;
//         if(dupIdx != -1) return S.substr(dupIdx, hi);

//         dupIdx = searchSubstring(S, lo - 1, sz);
//         //cout << lo-1 << " " << dupIdx << endl;
//         return dupIdx != -1 ? S.substr(dupIdx, lo-1) : "";
  }
};


// todo: the following solution got accepted ...
// class Solution {
// public:

// int p=1e7+7;

// vector<long long>roll;

// bool isMatch(string s,int len,int size,string & ans){

//     int hash=0;

//     for(int i=0;i<size;i++){

//         hash=(hash*26 + (s[i]-'a'))%p;

//     }

//     unordered_map<int,vector<int>>mp;

//     mp[hash].push_back(0);

//     for(int j=size;j<len;j++){

//         hash=((hash-roll[size-1]*(s[j-size]-'a'))%p+p)%p;
//         hash=(hash*26 + (s[j]-'a'))%p;

//         if(mp.find(hash)!=mp.end()){

//             for(int start:mp[hash]){

//                 string temp=s.substr(start,size);
//                 string curr=s.substr(j-size+1,size);

//                 if(temp==curr){

//                     ans=temp;
//                     return true;

//                 }

//             }

//         }

//         mp[hash].push_back(j-size+1);

//     }

//     return false;

// }

// string longestDupSubstring(string s) {

//     int len=s.length();

//     int low=1,high=len;

//     string ans="";

//     roll.resize(len);

//     roll[0]=1;

//     for(int i=1;i<len;i++){

//         roll[i]=(26 * roll[i-1])%p;

//     }

//     while(low<=high){

//         int mid=(low+high)/2;

//         string temp="";

//         bool flag=isMatch(s,len,mid,temp);

//         if(flag==true){

//             if(temp.length()>ans.length()){
//                 ans=temp;
//             }

//             low=mid+1;

//         }

//         else{

//             high=mid-1;

//         }

//     }

//     return ans;

// }
// };