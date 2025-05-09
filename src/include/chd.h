/*
 * Copyright (C) 2023-2024  April8th
 * chd - Containerized Hosting Daemon
 * Header file with API declarations
 */

#ifndef CHD_H
#define CHD_H

/*----- System Headers (Alphabetical Order) -----*/
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*----- Project Headers -----*/
#include "color.h"
#include "config.h"

/*----- Platform Requirements -----*/
#if !defined(__linux__)
#    error "This program requires Linux operating system"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*----- Status Codes -----*/
#define CHD_SUCCESS 0
#define CHD_ERR_SYSCALL -1
#define CHD_ERR_INVALID_ARG -2
#define CHD_ERR_IO -3
#define CHD_ERR_HASH -4

/*----- API Declarations -----*/
int check_sha256(const char* rfs_dir);
int execute_command(const char* cmd);

    void printc(ForegroundColor fg, BackgroundColor bg, TextStyle style, const char *format, ...);
void down_help(void);
int downloader(const char *url, const char *filename);
int pull(const char* pod_name, const char* pod_ver);
int get_file_type(char filedir[]);
void print_help(const char* pname);
void remove_files(const char* path);
char* calculate_file_sha256(const char* file_path);
const char* get_arch(void);
void run_proot_container(const char *container_dir);
int extract(const char *filename, const char *destdir);
void init_container(const char *dir);
char *find_container_path(const char *container_name);
 int delete_path(const char *path);
 void list_installed_containers(void);
#ifdef __cplusplus
}
#endif

#endif // CHD_H