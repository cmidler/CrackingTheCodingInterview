//
//  main.c
//  CrackingTheCodingInterview
//
//  Created by Chase Midler on 8/26/15.
//  Copyright (c) 2015 cmidler. All rights reserved.
//

#include "main.h"


int main(int argc, const char * argv[]) {
    // Arrays and strings
    /*
    printf("Question 1 should be false = %d\n", allUniqueChars("Test12"));
    printf("Question 1 should be true = %d\n", allUniqueChars("True12"));
    
    char reverseString[] = "TestIng";
    printf("String before reverse is %s\n", reverseString);
    reverse(reverseString);
    printf("String after reverse is %s\n", reverseString);
    
    printf("Question 1.3 is a permutation %d\n", isPermutationOfString("Yes It Is", "II sts eY"));
    printf("Question 1.3 is not a permutation %d\n", isPermutationOfString("Nope it isn't", "Sure ain't"));
    
    char spaceString[30] = "This is a test string";
    printf("Question 1.4 replaces spaces for before = %s", spaceString);
    replaceAllSpacesInString(spaceString);
    printf(" and after %s\n", spaceString);
    
    
    char* compressedString1 = "Test";
    char* compressedString2 = "aabccccs";
    printf("Question 1.5 should return normal string %s == %s and compressed string %s != %s\n", compressedString1, compressedString(compressedString1), compressedString2, compressedString(compressedString2));
    
    int* first = malloc(sizeof(int*)*3);
    int* second = malloc(sizeof(int*)*3);
    int* third = malloc(sizeof(int*)*3);
    
    for(int i = 1; i<=3; i++)
    {
        first[i-1] = 10+i;
        second[i-1] = 20+i;
        third[i-1] = 30+i;
    }
    
    int** matrix = malloc(sizeof(int*)*3);
    matrix[0] = first;
    matrix[1] = second;
    matrix[2] = third;
    
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    rotateImageByNinetyDegrees(matrix, 3);
    
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    free(first);
    free(second);
    free(third);
    free(matrix);
    
    first = malloc(sizeof(int*)*3);
    second = malloc(sizeof(int*)*3);
    third = malloc(sizeof(int*)*3);
    int* fourth = malloc(sizeof(int*)*3);
    for(int i = 1; i<=3; i++)
    {
        first[i-1] = 10+i;
        second[i-1] = 20+i;
        third[i-1] = 30+i;
        fourth[i-1] = 40+i;
    }
    
    second[1] = 0;
    
    
    matrix = malloc(sizeof(int*)*4);
    matrix[0] = first;
    matrix[1] = second;
    matrix[2] = third;
    matrix[3] = fourth;
    
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    setMXNMatrixRowAndColumnToZero(matrix, 4, 3);
    
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    free(first);
    free(second);
    free(third);
    free(fourth);
    free(matrix);
    
    
    printf("Question 1.8 should return false for normal != ornalm: %d\n", isRotation("normal", "ornalm"));
    printf("Question 1.8 should return true for waterbottle = erbottlewat: %d\n", isRotation("waterbottle", "erbottlewat"));
    
    //Linked Lists
    node_lla* head = malloc(sizeof(node_lla));
    node_lla* ptr = head;
    head->data = 1;
    for(int i = 0; i < 10; i++)
    {
        node_lla* newNode = malloc(sizeof(node_lla));
        newNode->next = NULL;
        newNode->data = i%3;
        ptr->next = newNode;
        ptr = newNode;
    }
    
    printf("Question 2.1: testing out deleting duplicates in linked list\n");
    ptr = head;
    while(ptr !=NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\t before\n");
    
    deleteDuplicateNodesWithoutTemporaryBuffer(head);
    
    ptr = head;
    while(ptr !=NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\t after\n\n");
    
    //free
    ptr = head;
    while(ptr!=NULL)
    {
        node_lla* tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
    
    node_llb* headB = malloc(sizeof(node_llb));
    node_llb* ptrB = headB;
    headB->value = 0;
    headB->next = NULL;
    for(int i = 1; i<10; i++)
    {
        node_llb* newNodeB = malloc(sizeof(node_llb));
        newNodeB->value = i;
        ptrB->next = newNodeB;
        newNodeB->next = NULL;
        ptrB = newNodeB;
    }
    
    //question 2.2
    printf("Question 2.2: Find kth node from last is %d and should be 4\n", findKthToLastElementInList(headB, 6)->value);
    
    //free
    ptrB = headB;
    while(ptrB!=NULL)
    {
        node_llb* tmp = ptrB->next;
        free(ptrB);
        ptrB = tmp;
    }
    
    
    node_llc* headC = malloc(sizeof(node_llc));
    node_llc* ptrC = headC;
    node_llc* deleteC = NULL;
    headC->value = 0;
    headC->next = NULL;
    for(int i = 1; i<10; i++)
    {
        node_llc* newNodeC = malloc(sizeof(node_llc));
        newNodeC->value = i;
        ptrC->next = newNodeC;
        newNodeC->next = NULL;
        ptrC = newNodeC;
        
        if(i == 5)
            deleteC = newNodeC;
    }
    
    //question 2.3
    printf("Question 2.3: Delete node in middle (5)\n");
    deleteNodeInMiddle(deleteC);
    
    
    //free
    ptrC = headC;
    while(ptrC!=NULL)
    {
        printf("%d,", ptrC->value);
        node_llc* tmp = ptrC->next;
        free(ptrC);
        ptrC = tmp;
    }
    
    printf("\n");
    
    
    node_lld* headD = malloc(sizeof(node_lld));
    node_lld* ptrD = headD;
    headD->value = 6;
    headD->next = NULL;
    for(int i = 1; i<20; i++)
    {
        node_lld* newNodeD = malloc(sizeof(node_lld));
        srand((unsigned int)time(NULL));
        newNodeD->value = abs((rand()*i % 20));
        ptrD->next = newNodeD;
        newNodeD->next = NULL;
        ptrD = newNodeD;
    }
    
    //question 2.4
    printf("Question 2.4: Reorder around (6)\n");
    ptrD = partitionLL(headD, 6);
    
    
    //free
    while(ptrD!=NULL)
    {
        printf("%d,", ptrD->value);
        node_lld* tmp = ptrD->next;
        free(ptrD);
        ptrD = tmp;
    }
    
    printf("\n");
    
    
    node_lle* nodeE1 = malloc(sizeof(node_lle));
    nodeE1->value = 7;
    node_lle* nodeE2 = malloc(sizeof(node_lle));
    nodeE2->value = 1;
    node_lle* nodeE3 = malloc(sizeof(node_lle));
    nodeE3->value = 6;
    nodeE1->next = nodeE2;
    nodeE2->next = nodeE3;
    nodeE3->next = NULL;
    
    node_lle* nodeE4 = malloc(sizeof(node_lle));
    nodeE4->value = 5;
    node_lle* nodeE5 = malloc(sizeof(node_lle));
    nodeE5->value = 9;
    node_lle* nodeE6 = malloc(sizeof(node_lle));
    nodeE6->value = 2;
    nodeE4->next = nodeE5;
    nodeE5->next = nodeE6;
    nodeE6->next = NULL;
    
    
    printf("Question 2.5: LL Addition part 1:\n");
    
    node_lle* ptrE = addReverseOrderLL(nodeE1, nodeE4);
    
    //free
    while(ptrE!=NULL)
    {
        printf("%d,", ptrE->value);
        node_lle* tmp = ptrE->next;
        free(ptrE);
        ptrE = tmp;
    }
    
    printf("\n");
    
    printf("Question 2.5: LL Addition part 2:\n");

    ptrE = addForwardOrderLL(nodeE1, nodeE4);
    
    //free
    while(ptrE!=NULL)
    {
        printf("%d,", ptrE->value);
        node_lle* tmp = ptrE->next;
        free(ptrE);
        ptrE = tmp;
    }
    
    free(nodeE1);
    free(nodeE2);
    free(nodeE3);
    free(nodeE4);
    free(nodeE5);
    free(nodeE6);
    
    printf("\n");
    
    node_llf* headF = malloc(sizeof(node_llf));
    node_llf* ptrF = headF;
    headF->value = 0;
    headF->next = NULL;
    for(int i = 1; i<20; i++)
    {
        node_llf* newNodeF = malloc(sizeof(node_llf));
        newNodeF->value = i%3;
        ptrF->next = newNodeF;
        if(i==19)
        {
            node_llf* testPtr = headF->next->next->next->next->next;
            newNodeF->next = testPtr;
            printf("Bad node value is %d\n", testPtr->value);
        }
        ptrF = newNodeF;
    }
    
    printf("Question 2.6: LL Finding Broken Link In Circle: %d\n", findNodeInLoop(headF)->value);
    
    ptrF->next = NULL;
    ptrF = headF;
    //free
    while(ptrF!=NULL)
    {
        node_llf* tmp = ptrF->next;
        free(ptrF);
        ptrF = tmp;
    }
    
    node_llg* headG = malloc(sizeof(node_llg));
    node_llg* ptrG = headG;
    headG->value = 0;
    headG->next = NULL;
    for(int i = 1; i<5; i++)
    {
        node_llg* newNodeG = malloc(sizeof(node_llg));
        newNodeG->value = i%2;
        ptrG->next = newNodeG;
        ptrG = newNodeG;
    }
    
    printf("Question 2.7: Palindrome in LL should be true: %d\n", isLLPalindrome(headG));
    headG->value = 2;
    printf("Question 2.7: Palindrome in LL should be false: %d\n\n\n", isLLPalindrome(headG));
    ptrG = headG;
    //free
    while(ptrG!=NULL)
    {
        node_llg* tmp = ptrG->next;
        free(ptrG);
        ptrG = tmp;
    }

    //Starting Stacks
    stack_a** stackArrayA = createStacksOnArrayA(3);
    for(int i = 0; i<3;i++)
    {
        for(int j =0; j<10; j++)
            pushA(stackArrayA, i*10+j, i);
    }
    
    printf("Question 3.1: one array with 3 stacks:\nNow popping stack:");
    
    
    for(int i = 0; i<3; i++)
    {
        printf("%d,",popA(stackArrayA, i));
    }
    
    printf("\nNow peeking:");
    
    for(int i = 0; i<3; i++)
    {
        printf("%d,",peekA(stackArrayA, i));
    }
    printf("\nNow popping to first element:");
    
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<8;j++)
            popA(stackArrayA, i);
        printf("%d,",peekA(stackArrayA, i));
    }
    printf("\n");
    
    freeStackA(stackArrayA, 3);
    
    printf("Question 3.2: Have a min, push, pop in O(1):\n");
    
    stack_b* stackB = createStackB();
    
    
    for(int i = 0; i<20; i++)
    {
        srand((unsigned int)time(NULL));
        int random =rand()*(i+1)%20;
        pushB(stackB, random);
        printf("Pushing %d and min is now %d\n", random, minB(stackB));
    }
    
    for(int i = 0; i<20; i++)
    {
        printf("Popping %d and min is now %d\n", popB(stackB), minB(stackB));
    }
    
    freeStackB(stackB);
    
    
    set_of_stacks* setOfStack = createSetOfStacksC(3);
    printf("Question 3.3: SetOfStacks:\n");
    for(int i = 0; i < 10; i++)
    {
        pushC(setOfStack, i);
        printf("Pushing %d onto stack\n", i);
    }
    
    for(int i = 0; i<5; i++)
        printf("Popping %d off of stack\n", popC(setOfStack));
    for(int i = 10; i<20; i++)
    {
        pushC(setOfStack, i);
        printf("Pushing %d onto stack\n", i);
    }
    
    for(int i = 0; i<3; i++)
    {
        printf("Popping at stack 2: %d\n", popAt(setOfStack, 2));
    }
    
    printf("Popping off of top of stack should be 19 = %d\n", popC(setOfStack));
    freeStackC(setOfStack);
    
    stack_f* stackF = malloc(sizeof(stack_f));
    stackF->current = 0;
    stackF->max = 2;
    stackF->values = malloc(sizeof(int)*2);
    
    for(int i = 0; i<25; i++)
        pushF(stackF, ((i+1)%10));
    printf("\nQuestion 3.6: sorted stack\n");
    
    
    for(int i = 0; i<25; i++)
        printf("Highest current value in sorted stack is %d\n", popF(stackF));
    
    free(stackF->values);
    free(stackF);
    
    printf("Question 3.7: Dogs and cats shelter\n");
    
    queue_3_g* queue3G = malloc(sizeof(queue_3_g));
    queue3G->headCat = NULL;
    queue3G->headDog = NULL;
    queue3G->lastCat = NULL;
    queue3G->lastDog = NULL;
    
    for(int i = 0; i<20; i++)
    {
        enqueue(queue3G, i%2);
    }
    
    //dequeue any
    for(int i = 0; i< 5; i++)
    {
        node_3_g* node3G = dequeueAny(queue3G);
        printf("Dequeue any with type = %d\n", node3G->isDog);
        free(node3G);
    }
    
    while(queue3G->headDog!=NULL)
    {
        node_3_g* node3G = dequeueDog(queue3G);
        printf("Dequeue dog %d\n", node3G->isDog);
    }
    
    while(queue3G->headCat!=NULL)
    {
        node_3_g* node3G = dequeueCat(queue3G);
        printf("Dequeue cat %d\n", node3G->isDog);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    //Recursion
    printf("Question 9.1: Number of possible steps:\n");
    for(int i = 0; i<20; i++)
        printf("Number of hops for %d steps is %d\n", i, childRunSteps(i));
    
    printf("Question 9.2: Robot movement on X,Y matrix.\n");
    
    printf("Number of ways for robot to move recursively for 1x1 = %d\n", possiblePathsForRobotRecursive(1, 1));
    printf("Number of ways for robot to move recursively for 2x1 = %d\n", possiblePathsForRobotRecursive(2, 1));
    printf("Number of ways for robot to move recursively for 2x2 = %d\n", possiblePathsForRobotRecursive(2, 2));
    printf("Number of ways for robot to move recursively for 3x2 = %d\n", possiblePathsForRobotRecursive(3, 2));
    printf("Number of ways for robot to move recursively for 6x6 = %d\n", possiblePathsForRobotRecursive(6, 6));
    printf("Number of ways for robot to move recursively for 21x11 = %d\n", possiblePathsForRobotRecursive(21, 11));
    
    printf("Question 9.2 Followup: blocked paths.\n");
    int** blockedPaths = malloc(sizeof(int*)*2);
    blockedPaths[0] = malloc(sizeof(int)*2);
    blockedPaths[1] = malloc(sizeof(int)*2);
    blockedPaths[0][0] = 1;
    blockedPaths[0][1] = 1;
    blockedPaths[1][0] = 3;
    blockedPaths[1][1] = 1;
    printf("Number of ways for robot for 3x2 = %d\n", findPathsWithOffLimitsRecursive(3, 2, blockedPaths, 2));
    printf("Number of ways for robot for 5x3 = %d\n", findPathsWithOffLimitsRecursive(5, 3, blockedPaths, 2));
    free(blockedPaths[1]);
    free(blockedPaths[0]);
    free(blockedPaths);
    
    int distinctInts [10]  = {-12,-11,-2,3,23,34,35,45,46,56};
    int* intPtr = distinctInts;
    printf("Question 9.3: Distinct magic number index should be 3 = %d\n", findMagicWithDistinct(intPtr, 10, 0));
    int nonDisInts[10] = {-1,0,2,2,2,3,4,5,6,10};
    intPtr = nonDisInts;
    printf("Question 9.3: Non distinct magic number index should be 2 = %d\n", findMagicWithoutDistinct(intPtr, 10, 0));
    
    for(int i = 0; i<9; i++)
        intPtr[i] = -1;
    intPtr[9] = 9;
    printf("Question 9.3: Non distinct magic number index should be 9 = %d\n", findMagicWithoutDistinct(intPtr, 10, 0));
    
    for(int i = 0; i<10; i++)
        intPtr[i] = i;
    sets_d* allSets = allSubsetOfSet(intPtr, 10);
    
    printf("Question 9.4: Find all subsets in set:\n");
    for(int i = 0; i<allSets->numberOfSets; i++)
    {
        printf("Set %d contains: {", i);
        for(int j = 0; j<allSets->sets[i]->size; j++)
        {
            printf("%d,", allSets->sets[i]->set[j]);
        }
        printf("}\n");
    }
    freeSets(allSets);
    
    
    printf("Question 9.5: Get all permutations of a string: \"abac\"\n");
    char* perm = malloc(sizeof(char)*5);
    perm[0] = 'a';
    perm[1] = 'b';
    perm[2] = 'a';
    perm[3] = 'c';
    perm[4] = '\0';
    permutation(perm, 0, 4);
    printf("Question 9.5: My own take on getting unique permutations \"abac\":\n");
    uniqueCombinations(perm);
    
    free(perm);
    
    printf("Question 9.6: Parenthesis for n left and right:\n");
    printParens(3);
    
    printf("Question 9.7: Fill paint on original array:\n");
    int** paintArray = malloc(sizeof(int*)*4);
    
    for(int i = 0; i<4; i++)
    {
        int* newPArray = malloc(sizeof(int)*6);
        paintArray[i] = newPArray;
        for(int j = 0; j<6; j++)
        {
            if(i == 1 && j==1)
                newPArray[j] = 5;
            else if(i == 1 && j==2)
                newPArray[j] = 5;
            else if(i == 1 && j == 3)
                newPArray[j] = 5;
            else if(i==0 && j == 5)
                newPArray[j] = 5;
            else if (i == 3 && j == 5)
                newPArray[j] = 5;
            else if (i==2 && j == 1)
                newPArray[j] =5;
            else if(i==2 && j==3)
                newPArray[j] = 5;
            else
                newPArray[j] = 1;
        }
    }
    
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<6; j++)
        {
            printf("| %d ",paintArray[i][j]);
        }
        printf("\n");
    }
    
    paintFill(paintArray, 1, 2, 2, 4, 6);
    
    printf("\nAfter filling paint\n");
    
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<6; j++)
        {
            printf("| %d ",paintArray[i][j]);
        }
        printf("\n");
    }
    
    printf("Question 9.8: Infinite cents representation: %d\n", calculateCents(13));
    int* queenColumn = malloc(sizeof(int)*8);
    int solutions = 0;
    printf("Question 9.9: 8x8 Queen Problem: \n");
    arrangeQueens(8, 0, queenColumn, &solutions);
    free(queenColumn);
    
    printf("Question 11.1: Merging 2 sorted arrays into 1\n[");
    
    int* sortedArrayA = malloc(sizeof(int)*30);
    int* sortedArrayB = malloc(sizeof(int)*10);
    for(int i = 0; i< 10; i++)
    {
        sortedArrayA[i] = i;
        sortedArrayA[i+10] = 10+i;
        sortedArrayB[i] = i*2;
        
    }
    
    mergeAB(sortedArrayA, sortedArrayB, 20, 10);
    for(int i = 0; i<30; i++)
        printf("%d,",sortedArrayA[i]);
    
    printf("]\n");
    free(sortedArrayA);
    free(sortedArrayB);
    
    char** anagramStrings = malloc(sizeof(char*)*10);
    anagramStrings[0] = "abc";
    anagramStrings[1] = "bcd";
    anagramStrings[2] = "cde";
    anagramStrings[3] = "aba";
    anagramStrings[4] = "edf";
    anagramStrings[5] = "def";
    anagramStrings[6] = "efg";
    anagramStrings[7] = "mom";
    anagramStrings[8] = "ewr";
    anagramStrings[9] = "akg";
    
    
    char** testAnagram = sortAnagrams(anagramStrings, 10);
    printf("Question 11.2: Sorting anagrams:\n[");
    for(int i  = 0; i<10; i++)
        printf("%s,", testAnagram[i]);
    free(testAnagram);
    free(anagramStrings);
    printf("]\n");
    
    int* intArray = malloc(sizeof(int)*10);
    for(int i = 0; i< 10; i++)
    {
        intArray[i] = (i+2)%10;
        printf("array[%d] = %d\n", i, (i+2)%10);
    }
    
    printf("Question 11.3: Find element %d in rotated array: %d\n",9,findElementInRotatedArray(10, intArray, 9));
    
    char** testEmptyStringFind = malloc(sizeof(char*)*10);
    testEmptyStringFind[0] = "";
    testEmptyStringFind[1] = "as";
    testEmptyStringFind[2] = "";
    testEmptyStringFind[3] = "";
    testEmptyStringFind[4] = "we";
    testEmptyStringFind[5] = "";
    testEmptyStringFind[6] = "";
    testEmptyStringFind[7] = "zip";
    testEmptyStringFind[8] = "";
    testEmptyStringFind[9] = "";
    
    printf("Question 11.5: Find \"as\" in string array: %d\n", indexOfString(testEmptyStringFind, 10, "as"));
    printf("Question 11.5: Find \"we\" in string array: %d\n", indexOfString(testEmptyStringFind, 10, "we"));
    printf("Question 11.5: Find \"zip\" in string array: %d\n", indexOfString(testEmptyStringFind, 10, "zip"));
    free(testEmptyStringFind);
    
    int** matrix11F = malloc(sizeof(int*)*5);
    for(int i = 0; i<5; i++)
    {
        int* newIntPtr = malloc(sizeof(int)*4);
        matrix11F[i] = newIntPtr;
    }
    
    matrix11F[0][0] = 0;
    matrix11F[0][1] = 1;
    matrix11F[0][2] = 3;
    matrix11F[0][3] = 4;
    matrix11F[1][0] = 2;
    matrix11F[1][1] = 2;
    matrix11F[1][2] = 4;
    matrix11F[1][3] = 7;
    matrix11F[2][0] = 4;
    matrix11F[2][1] = 6;
    matrix11F[2][2] = 8;
    matrix11F[2][3] = 10;
    matrix11F[3][0] = 5;
    matrix11F[3][1] = 7;
    matrix11F[3][2] = 9;
    matrix11F[3][3] = 11;
    matrix11F[4][0] = 11;
    matrix11F[4][1] = 13;
    matrix11F[4][2] = 16;
    matrix11F[4][3] = 17;
    
    int* int11FPtr = findElementInMatrix(matrix11F, 5, 4, 6);
    if(int11FPtr!=NULL)
    {
        printf("Question 11.6: Find element in sorted matrix [%d,%d]\n", int11FPtr[0], int11FPtr[1]);
        free(int11FPtr);
    }
    
    stream_11_h* stream11H = createStream(5);
    track(stream11H, 5);
    track(stream11H, 1);
    track(stream11H, 4);
    track(stream11H, 4);
    track(stream11H, 13);
    track(stream11H, 5);
    track(stream11H, 9);
    track(stream11H, 7);
    track(stream11H, 13);
    track(stream11H, 3);
    
    for(int i = 0; i<10; i++)
        printf("%d,", stream11H->numbers[i]);
    printf("\n");
    
    printf("Question 11.8: Track rank of stream of numbers: %d, %d, %d, %d\n", getRankOfNumber(stream11H, 1),getRankOfNumber(stream11H, 3), getRankOfNumber(stream11H, 4), getRankOfNumber(stream11H, 13));
    
    printNextBits(10);
    
    char* recRev = malloc(sizeof(char)*8);
    recRev[0] = 'r';
    recRev[1] = 'e';
    recRev[2] = 'v';
    recRev[3] = 'e';
    recRev[4] = 'r';
    recRev[5] = 's';
    recRev[6] = 'e';
    recRev[7] = '\0';
    recursiveReverse1(recRev, 7);
    printf("Reverse = %s\n", recRev);
    free(recRev);
    
    printf("Spaces should be 3 = %d\n",count_spaces("this should be 3"));
    
    
    
    printf("Is palindrome is yes %d\n", ispalindrome2("ta at", 5));
    printf("Is palindrome is no %d\n", ispalindrome2("no at", 5));
    
    
    char* boobs = malloc(6);
    boobs[0] = 'b';
    boobs[1] = 'o';
    boobs[2] = 'o';
    boobs[3] = 'b';
    boobs[4] = 's';
    boobs[5] = '\0';
    replaceRec3(boobs, 'o', 'e');
    printf("Change string from boobs to beebs %s\n", boobs);
    
    
    
    
    int* mergeSortArray = malloc(sizeof(int)*11);
    mergeSortArray[0] = 91;
    mergeSortArray[1] = 90;
    mergeSortArray[2] = 89;
    mergeSortArray[3] = 70;
    mergeSortArray[4] = 71;
    mergeSortArray[5] = 72;
    mergeSortArray[6] = 88;
    mergeSortArray[7] = 9;
    mergeSortArray[8] = 13;
    mergeSortArray[9] = 12;
    mergeSortArray[10] = 1;
    
    mergeSort(mergeSortArray, 11);
    
    for(int i = 0; i < 11; i++)
        printf("%d,", mergeSortArray[i]);
    printf("\n");
    */
    
    return 0;
}



