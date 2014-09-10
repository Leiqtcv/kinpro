/**
 * @brief	This file contains the QtROS class which contains methods
 *          for communicating with other ROS nodes
 *
 * @file 	qtros.hpp
 * @author	Lennart Claassen
 * @date    Sep 08 2014
 */
#ifndef QT_ROS_H
#define QT_ROS_H

#include <ros/ros.h>
#include <vector>
#include <string>
#include <QThread>
#include <QObject>
#include <QStringListModel>
#include <QMutex>

#include <ros/network.h>
#include <ros/package.h>

#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <sstream>

using namespace std;

class QtROS: public QThread {
    Q_OBJECT

    signals:

        /**
         * @brief this signal is emitted when the ROS main loop is left
         */
        void rosShutdown();

    public slots:

    public:
        /**
         * @brief constructor of class QtROS
         */
        QtROS(int argc, char *argv[], const char* node_name);

        /**
         * @brief destructor of class QtROS
         */
        ~QtROS();

        /**
         * @brief This method returns the current NodeHandle
         * @return NodeHandle
         */
        ros::NodeHandle getNodeHandle() {
            return *nh;
        }

        /**
         * @brief This method contains the ROS event loop
         */
        void run();

    private:

        ros::NodeHandle* nh;

};
#endif
