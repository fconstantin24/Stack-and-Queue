#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 9999

typedef struct {
	/* Valoarea retinuta de catre nod. */
	char val[256];

	/* Pointer catre urmatorul element de tip nod. */
	struct stack_node_t *next;
} stack_node_t;
typedef struct {
	/* Capul listei inlantuite. */
	struct stack_node_t *head;

	/* Dimensiunea stivei. */
	unsigned int length;
} stack_t;

stack_t *stack_create();
stack_node_t *stack_node_create(char val[]);
void stack_push(stack_t *stack, char val[]);
char* stack_pop(stack_t *stack);
void afisare (FILE *input);
void stack_print(stack_t *stack);

int main()
{
    FILE *rf;
    FILE *wf;
    
    afisare(rf);
    return 0;
}

stack_t *stack_create()
{
	stack_t *stack;
     stack = malloc(sizeof(stack_t));
     stack->head = NULL;
	 stack->length = 0;
	return stack;
}

stack_node_t *stack_node_create(char val[])
{
	stack_node_t *node;

	/* TODO: TASK 2, a): Alocare si initializare nod. */
	node = (stack_node_t *)malloc(sizeof(stack_node_t));
    //node = malloc(sizeof(stack_node_t));
	strcpy(node->val, val);
	node->next = NULL;
	return node;
}

void stack_push(stack_t *stack, char val[])
{
	stack_node_t *node = NULL;
	node = malloc(sizeof(stack_node_t));
	/* TODO: Creeare nod. Adaugare in stiva. */
    strcpy(node->val, val);
	node->next = stack->head;
	stack->head = node;
}

// PROGRAMUL NU MERGE DIN CAUZA UNEI PROBLEME A FUNCTIEI POP 

char* stack_pop(stack_t *stack)
{
	//int val = 0;
    char val[256];

	/* TODO: Identificare nod de tipul 'stack_node_t' ce trebuie scos. */
	stack_node_t *node = malloc(sizeof(stack_node_t));
	node =(stack_node_t*) stack->head;
	/* TODO: Copiere valoare. Stergere nod.*/
	strcpy(val, node->val);
    stack->head = node->next;
	free(node);
    --(stack->length);
	return val;
}


void stack_print(stack_t *stack)
{
    FILE *f;

    f = fopen("output.txt", "w");
	stack_node_t *aux;/// = malloc(sizeof(stack_node_t));
	aux =(stack_node_t*) stack->head;
	/* TODO: Parcurgere si afisare. */
	while(aux != NULL){
		strcpy(aux->val, stack_pop(stack));
        fprintf(f, "%s\n", aux->val);
        
		aux = aux->next;
	}
}

void afisare (FILE *input)
{
    stack_t *cuvinte;
    char *cuvant;
    //char cuv_aux[256];
    char propozitie[BUF_MAX];
    char delim[4] = " ,.";
    cuvinte = stack_create();

    input = fopen("input.txt", "r");
    
    if(input) {
        if(fgets(propozitie, BUF_MAX, input)) {
            cuvant = strtok(propozitie, delim);
  
            while(cuvant != NULL) {
                //printf("%s\n", cuvant);
                stack_node_create(cuvant);
                stack_push(cuvinte, cuvant);
                cuvant = strtok(NULL, delim);
            }
        }
    }

    stack_print(cuvinte);

    
    fclose(input);
}
