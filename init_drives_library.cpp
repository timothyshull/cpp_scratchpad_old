#include <cstdlib>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <regex>
#include <fstream>
#include <sstream>
#include <iostream>
#include "init_drives_library.h"

namespace init_drives {
    void rtrim(std::string &s, char c) {
        if (s.empty())
            return;
        std::string::iterator p;
        for (p = s.end(); p != s.begin() && *--p == c;);
        if (*p != c)
            p++;
        s.erase(p, s.end());
    }

    std::string which(const char *cmd) {
        char buffer[128];
        char which_prefix[] = "/usr/bin/which ";
        char *new_cmd = std::strcat(which_prefix, cmd);
        std::string result{""};
        std::shared_ptr<FILE> pipe(popen(new_cmd, "r"), pclose);

        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }

        while (!feof(pipe.get())) {
            if (fgets(buffer, 128, pipe.get()) != nullptr)
                result += buffer;
        }

        rtrim(result, '\n');
        rtrim(result, ' ');

        return result;
    }

    std::map<std::string, std::string> get_exe() {
        std::map<std::string, std::string> return_map;

        return_map["dmsetup_exe"] = which("/sbin/dmsetup");
        return_map["sgdisk_exe"] = which("/usr/sbin/sgdisk");
        return_map["parted_exe"] = which("/sbin/parted");
        return_map["lsof_exe"] = which("/usr/sbin/lsof");
        return_map["multipath_exe"] = which("/sbin/multipath");
        return_map["mdadm_exe"] = which("/sbin/mdadm");
        return_map["mkfs_exe"] = which("/sbin/mkfs.xfs");

        return return_map;
    };

    void add_bootstrap_env() {
        char new_path[] = "/usr/lib:"
                "/usr/lib64:"
                "/lib:"
                "/lib64:"
                "/usr/bootstrap/lib:"
                "/usr/bootstrap/lib64:"
                "/usr/bootstrap/usr/lib64:"
                "/usr/bootstrap/usr/lib:"
                "/usr/bootstrap/usr/lib64/httpd/modules:"
                "/usr/bootstrap/usr/lib64/ruby/1.8/x86_64-linux:"
                "/usr/bootstrap/usr/local/lib64";

        ::setenv("LD_LIBRARY_PATH", new_path, 1);
    }

    class if_line : public std::string {
        friend std::istream &operator>>(std::istream &input_stream, if_line &line) {
            return std::getline(input_stream, line);
        }
    };

    template<typename It>
    void read_lines(std::istream &input_stream, It dest_iterator) {
        using input_it = std::istream_iterator<if_line>;
        std::copy(It(input_stream), It(), dest_iterator);
    }

    std::vector<std::string> get_mount_dirs() {
        DIR *dir;
        std::vector<std::string> return_entries;
        struct dirent *ent;
        // Can filter with the following regex but unnecessary
        // std::regex re("o such");
        if ((dir = opendir("/mnt")) != nullptr) {
            /* print all the files and directories within directory */
            while ((ent = readdir(dir)) != nullptr) {
                struct stat s;
                if (stat(ent->d_name, &s) == 0) {
                    if (s.st_mode & S_IFDIR) {
                        return_entries.emplace_back(std::string{ent->d_name});
                    }
                }
                closedir(dir);
            }
        }
        return return_entries;
    }

    void update_fstab() {
        std::ifstream in_file("/etc/fstab");
        std::stringstream accumulator;

        try {
            std::regex re(" xfs ");
            std::string tmp;

            while (getline(in_file, tmp)) {
                if (!tmp.empty()) {
                    std::smatch match;
                    if (std::regex_search(tmp, match, re) && match.size() > 1) {
                        continue;
                    } else {
                        accumulator << tmp;
                    }
                }
            }
        } catch (std::regex_error &e) {
            std::cerr << "An error occurred while searching lines in /etc/fstab" << std::endl;
            return;
            // Syntax error in the regular expression
        }

        in_file.close();

        int err = remove("/etc/fstab");

        if (err != -1) {
            std::ofstream out_file("/etc/fstab");
            out_file << accumulator.rdbuf();
            out_file.flush();
            out_file.close();
        } else {
            std::cerr << "Unable to remove /etc/fstab to update it" << std::endl;
        }
    }

    void umount_all() {}

    void standard_regex_seaarch() {
        std::string subject("Name: John Doe");
        std::string result;
        try {
            std::regex re("Name: (.*)");
            std::smatch match;
            if (std::regex_search(subject, match, re) && match.size() > 1) {
                result = match.str(1);
            } else {
                result = std::string("");
            }
        } catch (std::regex_error &e) {
            // Syntax error in the regular expression
        }
    }


}