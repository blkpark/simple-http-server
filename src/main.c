#include "server.h"

int main(int argc, const char * argv[]) {
  run_server();
  return 0;
}






//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/socket.h>
//#include <sys/types.h>
//#include <netinet/in.h>
//#include <unistd.h>
//#include <string.h>
//#include <pthread.h>
//
//#define BACKLOG_SIZE  20
//#define BUFFER_SIZE   1024
//
//
//void error_handle(char *msg);
//void *request_routine_serv_sock(void *data);
//
//int main(int argc, const char * argv[]) {
//
//    // declare server valiables.
//    struct sockaddr_in server_address;
//    int server_socket;
//    int port = 8000;
//    pthread_t p_thread;
//
//    memset(&server_address, 0, sizeof(server_address));
//    server_address.sin_addr.s_addr = htonl(INADDR_ANY);     // change 32bit long intger to network byte order (big endian)
//    server_address.sin_family = AF_INET;                    // set address family IPv4
//    server_address.sin_port = htons(port);                  // change network byte order
//    server_socket = socket(PF_INET, SOCK_STREAM, 0);        // create socket to IPv4 internet protocol
//
//    // socket bind (error : return -1)
//    if (bind(server_socket, (const struct sockaddr *)&server_address , sizeof(server_address)) < 0) error_handle("bind() Error\n");
//
//    while (1) {
//
//      if (listen(server_socket, BACKLOG_SIZE) != 1 ) {
//        //request_routine_serv_sock
//        int thread_id, status;
//        thread_id = pthread_create(&p_thread, NULL, request_routine_serv_sock, (void *)&server_socket);
//        if(thread_id < 0) error_handle("pthread_create() error");
//          pthread_detach(p_thread);
//          printf("thread_id : %d\n", thread_id);
//          printf("thread join : %d\n", status);
//        }
//    }
//    // close(server_socket);
//
//    return 0;
//}
//
//void *request_routine_serv_sock(void *data){
//
//  printf("================= request_routine_serv_sock ===============\n");
//  sleep(5);
//  FILE *request;
//  struct sockaddr_in client_address;
//  int server_socket, client_socket;
//  uint client_address_size = sizeof(client_address);
//  char *request_buffer;
//  int request_buffer_size;
//
//
//  server_socket = *((int *) data);
//  client_socket = accept(server_socket, (struct sockaddr*)&client_address,&client_address_size);
//  if (client_socket < 0) error_handle("accept() failed\n");
//
//
//  request = fdopen(client_socket, "r");                   // read client request
//  request_buffer = malloc(BUFFER_SIZE);             // malloc request_buffer
//  request_buffer_size = BUFFER_SIZE;
//
//  // get request
//  while (1) {
//    char request_inner_buffer[BUFFER_SIZE] = {0};
//    ssize_t recv_size = recv(client_socket, request_inner_buffer, BUFFER_SIZE, 0);
//
//    // EOF
//    if(recv_size == -1) break;
//
//    // realloc request_buffer_size
//    request_buffer_size = request_buffer_size + (int)recv_size;
//    request_buffer = realloc(request_buffer, request_buffer_size);
//
//    // concatenate request
//    strcat(request_buffer, request_inner_buffer);
//
//    // EOF
//    if(recv_size < BUFFER_SIZE) break;
//  }
//
//  char response_buffer[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello world!</body></html>";
//  send(client_socket,&response_buffer,strlen(response_buffer),0);
//  //  printf("\n==================== response\n%s\n", response_buffer);
//  //            printf("\n");
//  //  printf("\n==================== return_buffer (now_buffer_size : %d)\n%s", request_buffer_size, request_buffer);
//
//  free(request_buffer);
//  fclose(request);
//  close(client_socket);
//  return 0;
//}
