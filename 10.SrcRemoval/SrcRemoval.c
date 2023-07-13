// #include <stdio.h>
// #include <stdlib.h>
// typedef struct LinkedList
// {
//     int val;
//     struct LinkedList *next;
// } LL;
// LL *init(int n)
// {
//     LL *list = (LL *)malloc(n * sizeof(struct LinkedList));
//     return list;
// }
// LL *createNode(int k)
// {
//     LL *node = (LL *)malloc(sizeof(struct LinkedList));
//     node->val = k;
//     node->next = NULL;
//     return node;
// }
// void insert(LL *list, int v, int k)
// {
//     LL *temp = (list + v);
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     LL *node = createNode(k);
//     temp->next = node;
// }
// void printList(LL *list, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         LL *temp = (list + i);
//         while (temp->next != NULL)
//         {
//             printf("%d-->", temp->val);
//             temp = temp->next;
//         }
//         printf("%d-->X", temp->val);
//         printf("\n");
//     }
// }
// LL *findSrc(LL *list, int n)
// {
//     LL *src, *temp;
//     int f = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if ((list + i)->val != -1)
//             src = (list + i);
//         else
//             continue;
//         for (int j = 0; j < n; j++)
//         {
//             if (j == i)
//                 continue;
//             if ((list + j)->val != -1)
//                 temp = (list + j)->next;
//             else
//                 continue;
//             while (temp != NULL)
//             {
//                 if (temp->val == src->val)
//                 {
//                     f = 1;
//                     break;
//                 }
//                 else
//                     temp = temp->next;
//             }
//             if (f == 1)
//                 break;
//         }
//         if (f != 1)
//             return src;
//         else
//             f = 0;
//     }
//     return NULL;
// }
// void rmvSrc(LL *list, LL *src, int n)
// {
//     LL *temp;
//     for (int i = 0; i < n; i++)
//     {
//         if (i != src->val)
//             temp = (list + i);
//         else
//             continue;
//         while (temp->next != NULL)
//         {
//             if (temp->next->val == src->val)
//                 temp->next = temp->next->next;
//             else
//                 temp = temp->next;
//         }
//     }
// }
// void main()
// {
//     int n, k, ct = 0;
//     printf("Enter no of vertices\n");
//     scanf("%d", &n);
//     LL *list = init(n);
//     for (int i = 0; i < n; i++)
//     {
//         (list + i)->val = i;
//         (list + i)->next = NULL;
//     }
//     printf("Enter Adjacency Matrix\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &k);
//             if (k == 1)
//             {
//                 insert(list, i, j);
//             }
//         }
//     }
//     printList(list, n);
//     LL *sr;
//     printf("Topological order\n");
//     do
//     {
//         ct += 1;
//         sr = findSrc(list, n);
//         if (sr == NULL)
//             break;
//         printf("%d\t", sr->val);
//         rmvSrc(list, sr, n);
//         sr->val = -1;
//     } while (sr != NULL);
//     if (ct != n + 1)
//         printf("\nCycle detected\n");
// }
#include <stdio.h>

int graph[40][40], n, visited[40]={0}, indegree[40]={0};

void createGraph(){
	printf("No. of vertices>> ");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}

void main(){
	int i,j,count=0;
	
	createGraph();
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (graph[j][i]) indegree[i]++;
		}
	}
	
	printf("Topologically Sorted Order:\n");
	while(count<n){
		for(i=0;i<n;i++){
			if (!visited[i] && !indegree[i]){
				printf("%d-->",i);
				visited[i]=1;
				for(j=0;j<n;j++){
					if (graph[i][j]){
						graph[i][j]=0;
						indegree[j]--;
					}
				}
				count++;
				break;
			}
		}
	}
	printf("\n");
	
}