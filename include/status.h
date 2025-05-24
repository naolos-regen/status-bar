#ifndef STATUS_H
#define STATUS_H

#include <ifaddrs.h>
#include <sys/types.h>
static	struct	ifaddrs	*addr;
/*
struct		internet_protocol
{
	struct ifaddrs	*ifa;
	char		*ipv4;
	char		*ipv6;
};
*/
#include <sys/sysinfo.h>

static	struct	sysinfo	*info;
/*
struct		random_access_memory
{
	size_t	free_memory;
	size_t	total_memory;
	size_t	swap_free_memory;
	size_t	swap_total_memory;
	size_t	cached_memory;
	size_t	buffered_memory;
};
*/

#include <sys/statvfs.h>
static 	struct	statvfs	*disk_stats;
//	struct statvfs {
//               unsigned long  f_bsize;    /* Filesystem block size */
//               unsigned long  f_frsize;   /* Fragment size */
//               fsblkcnt_t     f_blocks;   /* Size of fs in f_frsize units */
//               fsblkcnt_t     f_bfree;    /* Number of free blocks */
//               fsblkcnt_t     f_bavail;   /* Number of free blocks for
//                                             unprivileged users */
//               fsfilcnt_t     f_files;    /* Number of inodes */
//               fsfilcnt_t     f_ffree;    /* Number of free inodes */
//               fsfilcnt_t     f_favail;   /* Number of free inodes for
//                                             unprivileged users */
//               unsigned long  f_fsid;     /* Filesystem ID */
//               unsigned long  f_flag;     /* Mount flags */
//               unsigned long  f_namemax;  /* Maximum filename length */
//           };

#include <time.h>
static	time_t		now;
static	struct 	tm 	*local;
/*
struct		date_time
{
	size_t		unix_time;
	size_t		time_offset;
	char		*string;
		
	// INFO: people's job to implement it and use it;
	char		*(*to_str)();
	int		 (*set_offset)(int);
};
*/
int		get_seconds(size_t unix_time);
int		get_minutes(size_t unix_time);
int		get_hours(size_t unix_time);
int		get_day(size_t unix_time);
int		get_month(size_t unix_time);
int		get_year(size_t unix_time);
size_t		get_unix_time();

// TODO: /sys/class/power_supply

struct		battery
{
	int		exists;
	int		charging;	// INFO: if charging time_left ^ if !charging time_left v
	int		percentage;
	size_t		time_left;	// INFO: this is in UNIX_time
};

int		get_percentage();
int		get_time_left();	// INFO: depending if Charging or Drowning



#endif //STATUS_H
