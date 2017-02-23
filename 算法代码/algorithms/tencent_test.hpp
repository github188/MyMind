#include <vector>
std::vector<int> arr;
int main(void)
{
	arr.data();
}

/* 1.���������ַ��� s1 �� s2 ���� s1 ��ɾ���� s2 �г��ֹ����ַ���*/
char * remove( char * s1, const char * s2 )
{
    if(s1 == NULL)
        return NULL;
    else if (s2 == NULL)
        return s1;
        
    char buk[256] = {0};
    for(int i = 0; s2[i] != '\0'; ++i)
    {
        ++buk[s2[i]];
    }
    
    std::vector<char> res;
    for(int i = 0; s1[i] != '\0'; ++i)
    {
        if(buk[s1[i]] <= 0)
            res.push_back(s1[i]);
        else
            --buk[s1[i]];
    }
    
    memcpy(s1, res.data(), res.size());
    return s1;
}

/* 2.����������� */
struct TreeNode {
����int val;
����struct TreeNode * left, * right;
};  

int depth(TreeNode* root, int level)
{
    if(root == NULL)
        return level;
    else if(root->left == NULL && root->right == NULL)
        return level+1;
    
    int leftDep = depth(root->left, level+1);
    int rightDep = depth(root->right, level+1);
    return (leftDep > rightDep)?(leftDep):(rightDep);
}
int depth( TreeNode * root )
{
    return depth(root, 0);
}


 
/* 3.������������ȥ���ظ���Ԫ�� */
(1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9) -> (1, 3, 5, 9).
struct LinkNode {
����int val;
����struct LinkNode * next;
};

void remove( LinkNode * head )
{
    if(head == NULL)
        return;
        
    LinkNode* cur = head;
    LinkNode* nxt = cur->next;
    while(nxt != NULL)
    {
        if(cur->val == nxt->val)
        {
            cur->next = nxt->next;
            delete nxt;
            nxt = cur->next;
        }
        else
        {
            cur = cur->next;
            nxt = cur->next;
        }
    }
}


/* 4.����һ������ѭ���������飬�������ҳ���С��Ԫ�أ�ʹ�õ��㷨Խ��Խ�á��ر�أ���С��Ԫ�ؿ��ܳ����������м䡣���磺50, 52, 63, 90, 3, 8, 15, 44�� */
int minNum(int array[], int index1, int index2)
{
    int res = array[index1];
    for(int i = index1+1; i <= index2; ++i)
    {
        if(res > array[i])
            res = array[i];
    }
    return res;
}
int findmin( int array[], int count )
{
    assert(array != NULL && count > 0);
    if(count == 1)
        return array[0];
        
    int ix1 = 0;
    int ix2 = count-1;
    int ixMid = ix1;
    while(array[ix1] >= array[ix2])
    {
        if(ix2 - ix1 == 1)
        {
            ixMid = ix2;
            break;
        }
        ixMid = (ix1 + ix2)/2;
        
        //ֻ��˳�����
        if(array[ix1] == array[ix2]
            && array[ixMid] == array[ix1])
            return minNum(array, ix1, ix2);
        
        if(array[ixMid] >= array[ix1])
            ix1 = ixMid;
        else if(array[ixMid] <= array[ix2])
            ix2 = ixMid;
    }
    
    return array[ixMid];
}


/* 5.��һ�����������У��ҳ�����������������С�*/
struct Result {
    int offset; // ���еĿ�ʼλ��
    int count;  // ���еĳ���
};
int findCont( int array[], int count, struct Result * result )
{
	if(array == NULL || count <= 0)
	{
		result->offset = -1;
		result->count = 0;
		return 0;
	}

	struct Result res = {0, 1};
	int pre = array[0];
	result->offset = 0;
	result->count = 1;
	for(int i = 1; i < count; ++i)
	{
		if(array[i] >= pre)
		{
			pre = array[i];
			if(++res.count > result->count)
				*result = res;
		}
		else
		{
			pre = array[i];
			res.offset = i;
			res.count = 1;
		}
	}
	return result->count;
}

/* 6 �ж�һ���������Ƿ���ֻ����ռ临�ӶȲ�����O(N) */
struct LinkNode {
    struct LinkNode * next;
};

/* ���� 1���л���0���޻� */
int iscycle( struct LinkNode * head )
{
	if(head == NULL)
		return 0;
	else if(head->next == NULL)
		return 1;

	struct LinkNode *cur1 = head, *cur2 = head;
	int res = 0;
	do
	{
		cur1 = cur1->next;
		if(cur2->next == NULL || cur2->next->next == NULL)
			break;//�޻�
		else
			cur2 = cur2->next->next;

		if(cur1 == cur2)
		{//�л�
			res = 1;
			break;
		}
	}while(cur1 != NULL && cur2 != NULL);
	return res;
}


/* 7 �ж��������Ƿ��ǶԳ�������3��121��12321�����ܰ�����תΪ�ַ������жϡ�*/

/* ���� 1���Գƣ�0�����Գ� */
int ismirror( int value )
{
	std::vector<int> valArr;
	for(; value > 0; value /= 10)
		valArr.push_back(value % 10);

	int high = valArr.size()-1;
	int low = 0;
	int *arr = valArr.data();
	for(; low < high; ++low, --high)
	{
		if(*(arr+low) != *(arr+high))
		{
			return 0;
		}
	}
	return 1;
}

/* 8 �ж����´���λ�������ٸ�x�����ȥ���س����Ƕ��ٸ�x�� */
//6, 8
for( int i = 0; i < 2; i++ )
{
    fork();
    printf("x\n");
}




