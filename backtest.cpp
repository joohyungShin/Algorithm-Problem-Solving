#include <cstdio>
#include <stack>
#include <utility>

using namespace std;
int main() {
    int n;
    int arr[300001] = {0};
    stack< pair<int,int> > st;
    long long res = 0;
    
    scanf("%d", &n);
    
    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* created pair to save to value and location of height */
    st.push(make_pair(arr[1],1));
    int lo = 2;
    
    while(true) {
        pair<int, int> top = st.top();
        pair<int, int> tar = make_pair(arr[lo], lo);
        if(top.first < tar.first) {
            while (!st.empty()) {
                pair<int, int> rtop = st.top();
                if (rtop.first >= tar.first) {
                    res += rtop.second;
                    break;
                }
                st.pop();
            }
            st.push(tar);
        } else {
            res += top.second;
            st.push(tar);
        }
        
        if (lo == n) break;
        lo++;
    }
    printf("%lld\n", res);
    return 0;
}
