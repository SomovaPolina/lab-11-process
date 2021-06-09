// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_BUILDER_HPP_
#define INCLUDE_BUILDER_HPP_

#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/process.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <async++.h>
#include <pthread.h>
#include <future>
#include "process.hpp"

const char error[] = "Error\n"
                     "Write to get Help: --help or -h";

class Builder{
public:
    static void create_program_options(
            boost::program_options::options_description& desc,
            boost::program_options::variables_map&
            vmap, const int& argc, const char *argv[]);

    void start(const boost::program_options::variables_map& vmap);

    void init(const boost::log::trivial::severity_level& sev_lvl);

    boost::log::trivial::severity_level choose_sev_lvl(const std::string&
    sev_lvl_str);

    void settings_process(const boost::program_options::variables_map& vmap);

    bool run_process(const std::string& target, Process_info& process_info);

    ~Builder();

private:
    Process* p_process;
};

#endif // INCLUDE_BUILDER_HPP_