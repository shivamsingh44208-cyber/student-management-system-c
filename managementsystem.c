#include <stdio.h>

typedef struct student{                            //typedef is used to giving a name to aur defined structure datatype
    int roll_no;                                   // == STD
    char name[50];
    float marks;
} STD;

int main(){
    int n;
    printf("NO OF STUDENTS: ");
    scanf("%d", &n);
    STD s[50];      // fixed size array so we have room to insert more students later

    for(int i = 0; i<=n-1; i++){
        printf("\nStudent %d\n", i+1);
        printf("Enter roll no.: ");
        scanf("%d", &s[i].roll_no);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter marks obtained: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nRoll no\tName\tMarks\n");
    for(int i = 0; i<=n-1; i++){
        printf("%d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    }

    // ---------- INSERTION ----------
    // insert a new student at any index/position we choose
    int pos;
    printf("\n--- Insert new student ---\n");
    printf("Enter index/position to insert at (0 to %d): ", n);
    scanf("%d", &pos);

    // shift every student from pos onwards, one step forward
    // to make an empty slot at pos
    for(int i = n; i > pos; i--){
        s[i] = s[i-1];
    }

    printf("Enter roll no.: ");
    scanf("%d", &s[pos].roll_no);
    printf("Enter name: ");
    scanf("%s", s[pos].name);
    printf("Enter marks obtained: ");
    scanf("%f", &s[pos].marks);
    n++;    // one more student added, so increase n

    printf("\nList after insertion:\n");
    printf("Roll no\tName\tMarks\n");
    for(int i = 0; i<=n-1; i++){
        printf("%d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    }

    // ---------- SEARCHING ----------
    int search_roll;
    printf("\n--- Search student ---\n");
    printf("Enter roll no. to search: ");
    scanf("%d", &search_roll);

    for(int i = 0; i<=n-1; i++){
        if(s[i].roll_no == search_roll){
            printf("Found: %d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
        }
    }

    // ---------- DELETION ----------
    int delete_roll;
    printf("\n--- Delete student ---\n");
    printf("Enter roll no. to delete: ");
    scanf("%d", &delete_roll);

    for(int i = 0; i<=n-1; i++){
        if(s[i].roll_no == delete_roll){
            // shift every student after this one, one step back
            for(int j = i; j<n-1; j++){
                s[j] = s[j+1];
            }
            n--;    // one less student now
            break;
        }
    }

    printf("\nList after deletion:\n");
    printf("Roll no\tName\tMarks\n");
    for(int i = 0; i<=n-1; i++){
        printf("%d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    }

    return 0;
}