#include <bits/stdc++.h>
using namespace std;
bool chk;
 
struct Trie {
    bool finish; // ������ ������ ǥ������
    Trie* next[10]; // 26���� ���ĺ��� ���� Ʈ����

    // ������
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    // �Ҹ���
    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (next[i])
                delete next[i];
    }

    // Ʈ���̿� ���ڿ� ����
    void insert(const char* key) {
        if (*key == '\0')
            finish = true; // ���ڿ��� ������ ������ ��� ǥ��
        else {
            int curr = *key - '0';
            if (next[curr] == NULL)
                next[curr] = new Trie(); // Ž���� ó���Ǵ� ������ ��� �����Ҵ�
            next[curr]->insert(key + 1); // ���� ���� ����
        }
    }

    // Ʈ���̿��� ���ڿ� ã��
    bool find(char *str) {
		//������ �����ϸ� return false
		if (*str == '\0') {
			return false;
		}
		//�߰��� finish�� ������ �ϰ��� x (� ��ȭ��ȣ�� �ٸ� ��ȭ��ȣ�� ���ξ �Ǹ�)
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
