#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX];
    int n = 0;   // number of elements
    int choice, pos, value, i, found = 0;

    do
    {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Update Element\n");
        printf("7. Sort Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements:\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            break;

        case 2:
            if (n == 0)
            {
                printf("Array is empty!\n");
            }
            else
            {
                printf("Array elements are:\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            break;

        case 3:
            if (n == MAX)
            {
                printf("Array is full!\n");
            }
            else
            {
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);

                for (i = n; i > pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                printf("Element inserted successfully.\n");
            }
            break;

        case 4:
            if (n == 0)
            {
                printf("Array is empty!\n");
            }
            else
            {
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);

                for (i = pos; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully.\n");
            }
            break;

        case 5:
            found = 0;
            printf("Enter element to search: ");
            scanf("%d", &value);

            for (i = 0; i < n; i++)
            {
                if (arr[i] == value)
                {
                    printf("Element found at position %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Element not found!\n");
            }
            break;

        case 6:
            printf("Enter position to update (0 to %d): ", n - 1);
            scanf("%d", &pos);
            printf("Enter new value: ");
            scanf("%d", &value);
            arr[pos] = value;
            printf("Element updated successfully.\n");
            break;

        case 7:
            for (i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Array sorted in ascending order.\n");
            break;

        case 8:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}
