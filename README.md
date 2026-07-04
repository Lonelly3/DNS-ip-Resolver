# DNS IP Resolver

A minimalistic DNS resolver written in C for quickly resolving domain names to IP addresses.

## Features

- Resolve domain names to IPv4 addresses
- Uses WinSock API
- Lightweight console application

## Build

```bash
gcc main.c -o resolver.exe -lws2_32
```

## Usage

```bash
resolver.exe google.com
```

## Example

```
Enter domain:
google.com

IPv4:
142.250.184.14
```
## Technologies

- C
- WinSock2
- Windows API
  

