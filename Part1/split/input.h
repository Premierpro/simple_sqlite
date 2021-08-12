#ifndef INPUT_H
#define INPUT_H

typedef struct {
	char *buffer;
	size_t buffer_length;
	ssize_t input_length;
} InputBuffer;

void print_prompt() 
{ 
	printf("db > "); 
}

InputBuffer *new_input_buffer () {
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;
					
	return input_buffer;
}

void close_input_buffer(InputBuffer *input_buffer) {
	free(input_buffer->buffer);
	free(input_buffer);
}

void read_input(InputBuffer *input_buffer) {
	ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
		
	if (bytes_read < 0) {
		printf("Error reading input\n");
		exit(EXIT_FAILURE);
	}
			
	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[input_buffer->input_length] = '\0';
					
	return ;
}
#endif