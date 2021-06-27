#ifndef _NETWORKING_HEADER_INCLUDED_H_
#define _NETWORKING_HEADER_INCLUDED_H_

const enum _STATUS_CODES {
    OK = 200,
    NOT_FOUND = 404
};

typedef enum _STATUS_CODES STATUS_CODES;

const char *generate_headers(const char *dest, STATUS_CODES status, const char *body);

#endif // _NETWORKING_HEADER_INCLUDED_H_
