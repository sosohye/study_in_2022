#include <bits/stdc++.h>
using namespace std;
bool chk;
 
struct Trie {
    bool finish; // 끝나는 지점을 표시해줌
    Trie* next[10]; // 26가지 알파벳에 대한 트라이

    // 생성자
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    // 소멸자
    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (next[i])
                delete next[i];
    }

    // 트라이에 문자열 삽입
    void insert(const char* key) {
        if (*key == '\0')
            finish = true; // 문자열이 끝나는 지점일 경우 표시
        else {
            int curr = *key - '0';
            if (next[curr] == NULL)
                next[curr] = new Trie(); // 탐색이 처음되는 지점일 경우 동적할당
            next[curr]->insert(key + 1); // 다음 문자 삽입
        }
    }

    // 트라이에서 문자열 찾기
    bool find(char *str) {
		//끝까지 도달하면 return false
		if (*str == '\0') {
			return false;
		}
		//중간에 finish가 있으면 일관성 x (어떤 전화번호가 다른 전화번호의 접두어가 되면)
		if (finish == true)
			return true;

		int Cur = *str - '0';
		if (next[Cur] == NULL) return false;
		return next[Cur]->find(str + 1);
	}
};



int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		char num[10009][19];
		Trie* root = new Trie;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",num[i]);
			root->insert(num[i]);
		}
		for(i=0;i<n;i++)
		{
			if(root->find(num[i]))
			{
				printf("NO\n");
				break;
			}
		}
		if(i==n)	printf("YES\n");
	}
	return 0;
}
