BEGIN {
D["PACKAGE_NAME"]=" \"ltp\""
D["PACKAGE_TARNAME"]=" \"ltp\""
D["PACKAGE_VERSION"]=" \"LTP_VERSION\""
D["PACKAGE_STRING"]=" \"ltp LTP_VERSION\""
D["PACKAGE_BUGREPORT"]=" \"ltp@lists.linux.it\""
D["PACKAGE_URL"]=" \"\""
D["PACKAGE"]=" \"ltp\""
D["VERSION"]=" \"LTP_VERSION\""
D["STDC_HEADERS"]=" 1"
D["HAVE_SYS_TYPES_H"]=" 1"
D["HAVE_SYS_STAT_H"]=" 1"
D["HAVE_STDLIB_H"]=" 1"
D["HAVE_STRING_H"]=" 1"
D["HAVE_MEMORY_H"]=" 1"
D["HAVE_STRINGS_H"]=" 1"
D["HAVE_INTTYPES_H"]=" 1"
D["HAVE_STDINT_H"]=" 1"
D["HAVE_UNISTD_H"]=" 1"
D["HAVE_IFADDRS_H"]=" 1"
D["HAVE_PTHREAD_H"]=" 1"
D["HAVE_SYS_XATTR_H"]=" 1"
D["HAVE_LINUX_GENETLINK_H"]=" 1"
D["HAVE_LINUX_MEMPOLICY_H"]=" 1"
D["HAVE_LINUX_NETLINK_H"]=" 1"
D["HAVE_SYS_EPOLL_H"]=" 1"
D["HAVE_SYS_INOTIFY_H"]=" 1"
D["HAVE_SYS_FANOTIFY_H"]=" 1"
D["HAVE_SYS_PRCTL_H"]=" 1"
D["HAVE_MKDTEMP"]=" 1"
D["HAVE_SYS_PTRACE_H"]=" 1"
D["HAVE_ASM_PTRACE_H"]=" 1"
D["HAVE_LINUX_PTRACE_H"]=" 1"
D["HAVE_STRUCT_PT_REGS"]=" 1"
D["HAVE_DECL_PTRACE_GETSIGINFO"]=" 1"
D["HAVE_DECL_PTRACE_O_TRACEVFORKDONE"]=" 1"
D["HAVE_DECL_PTRACE_SETOPTIONS"]=" 1"
D["HAVE_FORK"]=" 1"
D["HAVE_DAEMON"]=" 1"
D["HAVE_VFORK"]=" 1"
D["HAVE_SYS_PRCTL_H"]=" 1"
D["HAVE_DECL_PR_CAPBSET_DROP"]=" 1"
D["HAVE_DECL_PR_CAPBSET_READ"]=" 1"
D["HAVE_LINUX_SECUREBITS_H"]=" 1"
D["HAVE_STRUCT_SIGACTION_SA_SIGACTION"]=" 1"
D["HAVE_LINUX_MEMPOLICY_H"]=" 1"
D["HAVE_DECL_MPOL_BIND"]=" 0"
D["HAVE_DECL_MPOL_DEFAULT"]=" 0"
D["HAVE_DECL_MPOL_F_ADDR"]=" 0"
D["HAVE_DECL_MPOL_F_MEMS_ALLOWED"]=" 0"
D["HAVE_DECL_MPOL_F_NODE"]=" 0"
D["HAVE_DECL_MPOL_INTERLEAVE"]=" 0"
D["HAVE_DECL_MPOL_PREFERRED"]=" 0"
D["HAVE_QUOTAV2"]=" 1"
D["HAVE_SIGNALFD"]=" 1"
D["HAVE_SYS_SIGNALFD_H"]=" 1"
D["HAVE_LINUX_TYPES_H"]=" 1"
D["HAVE_LINUX_SIGNALFD_H"]=" 1"
D["HAVE_STRUCT_SIGNALFD_SIGINFO_SSI_SIGNO"]=" 1"
D["HAVE_UNSHARE"]=" 1"
D["HAVE_UTIMENSAT"]=" 1"
D["HAVE_LINUX_TASKSTATS_H"]=" 1"
D["HAVE_STRUCT_TASKSTATS_FREEPAGES_COUNT"]=" 1"
D["HAVE_STRUCT_TASKSTATS_NVCSW"]=" 1"
D["HAVE_STRUCT_TASKSTATS_READ_BYTES"]=" 1"
D["HAVE_DECL_CLOCK_MONOTONIC_RAW"]=" 1"
D["HAVE_DECL_CLOCK_REALTIME_COARSE"]=" 1"
D["HAVE_DECL_CLOCK_MONOTONIC_COARSE"]=" 1"
D["HAVE_DECL_MADV_MERGEABLE"]=" 1"
D["HAVE_MADV_MERGEABLE"]=" 1"
D["HAVE_FS_IOC_FLAGS"]=" 1"
D["HAVE_MREMAP_FIXED"]=" 1"
D["CLONE_SUPPORTS_7_ARGS"]=" 1"
D["HAVE_MKDIRAT"]=" 1"
D["HAVE_FCHOWNAT"]=" 1"
D["HAVE_FSTATAT"]=" 1"
D["HAVE_MKNODAT"]=" 1"
D["HAVE_READLINKAT"]=" 1"
D["HAVE_OPENAT"]=" 1"
D["HAVE_RENAMEAT"]=" 1"
D["HAVE_FALLOCATE"]=" 1"
D["HAVE_STRUCT_F_OWNER_EX"]=" 1"
D["HAVE_PERF_EVENT_ATTR"]=" 1"
D["HAVE_TEE"]=" 1"
D["HAVE_SPLICE"]=" 1"
D["HAVE_VMSPLICE"]=" 1"
D["HAVE_TIMERFD_CREATE"]=" 1"
D["HAVE_TIMERFD_SETTIME"]=" 1"
D["HAVE_TIMERFD_GETTIME"]=" 1"
D["HAVE_SYS_TIMERFD_H"]=" 1"
D["HAVE_LINUX_CAN_H"]=" 1"
D["HAVE_STRUCT_IOVEC"]=" 1"
D["HAVE_LINUX_KEYCTL_H"]=" 1"
D["HAVE_LINUX_RANDOM_H"]=" 1"
D["HAVE_DECL_IFLA_NET_NS_PID"]=" 1"
D["HAVE_ENUM_KCMP_TYPE"]=" 1"
D["HAVE_PREADV"]=" 1"
D["HAVE_PWRITEV"]=" 1"
D["HAVE_EPOLL_PWAIT"]=" 1"
D["HAVE_SYNC_ADD_AND_FETCH"]=" 1"
D["HAVE_BUILTIN_CLEAR_CACHE"]=" 1"
D["HAVE_STRUCT_MMSGHDR"]=" 1"
D["HAVE_STRUCT_UTSNAME_DOMAINNAME"]=" 1"
D["HAVE_STRUCT_XT_ENTRY_MATCH"]=" 1"
D["HAVE_STRUCT_XT_ENTRY_TARGET"]=" 1"
  for (key in D) D_is_set[key] = 1
  FS = ""
}
/^[\t ]*#[\t ]*(define|undef)[\t ]+[_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ][_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]*([\t (]|$)/ {
  line = $ 0
  split(line, arg, " ")
  if (arg[1] == "#") {
    defundef = arg[2]
    mac1 = arg[3]
  } else {
    defundef = substr(arg[1], 2)
    mac1 = arg[2]
  }
  split(mac1, mac2, "(") #)
  macro = mac2[1]
  prefix = substr(line, 1, index(line, defundef) - 1)
  if (D_is_set[macro]) {
    # Preserve the white space surrounding the "#".
    print prefix "define", macro P[macro] D[macro]
    next
  } else {
    # Replace #undef with comments.  This is necessary, for example,
    # in the case of _POSIX_SOURCE, which is predefined and required
    # on some systems where configure will not decide to define it.
    if (defundef == "undef") {
      print "/*", prefix defundef, macro, "*/"
      next
    }
  }
}
{ print }
