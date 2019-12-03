#include <bits/stdc++.h>
#include <vector>

using namespace std;
struct node
{
	int data;
	struct node *next, *prev;
};
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head);
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second);
struct node *mergeSort(struct node *head)
{
	if (!head || !head->next)
		return head;
	struct node *second = splitList(head);
	head = mergeSort(head);
	second = mergeSort(second);
	return merge(head, second);
}
void insert(struct node **head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct node *head)
{
	struct node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = mergeSort(head);
        print(head);
    }
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the list is as
struct node
{
	int data;
	struct node *next, *prev;
};
*/
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head)
{
    if(head == NULL) return NULL;
    struct node *sec = NULL, *itr = head;
    int num = 0 , mid = 0;
    while(itr)
    {
        itr = itr->next;
        num++;
    }
    mid = num/2;
    itr = head;
    num = 0;
    while(itr && num != mid )
    {
        itr = itr->next;
        num++;
    }

    if(itr)
    {
        sec = itr->next;
        itr->next = NULL;
    }
    return sec;
}
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second)
{
    if (!first) return second;
    else if(!second) return first;

    struct node *itr = first, *sitr = second;
    vector<int> left, right;

    while(itr->next)
    {
        left.push_back(itr->data);
        itr = itr->next;
    }
    left.push_back(itr->data); //last node
    itr->next = second;

    while(sitr)
    {
        right.push_back(sitr->data);
        sitr = sitr->next;
    }

    int n = left.size(), m = right.size();
    int i = 0, j = 0;

    itr = first;
    while(i < n && m < j)
    {
        if(left[i] <= right[j])
        {
            itr->data = left[i];
            i++;
        }
        else
        {
            itr->data = right[j];
            j++;
        }
        itr = itr->next;
    }

    while(i < n)
    {
        itr->data = left[i];
        itr = itr->next;
        i++;
    }

    while(j < m)
    {
        itr->data = right[j];
        itr = itr->next;
        j++;
    }
    return first;
}
