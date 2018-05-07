/*
 *  Copyright (C) 2018 João Borrego
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *      
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*!
    \file examples/world_example/world_example.hh
    \brief World tools example client

    An example client to interact with WorldlUtils plugin

    \deprecated Since several features of WorldPlugin will be deprecated
    this example client will also be modified.

    \author João Borrego : jsbruglie
    \author Rui Figueiredo : ruipimentelfigueiredo
*/

// Gazebo
#include <gazebo/gazebo_client.hh>
#include <gazebo/gazebo_config.h>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

// I/O streams
#include <iostream>
// File streams
#include <fstream>
// Regular expressions
#include <regex>
// For iterating over the contents of a dir
#include <boost/filesystem.hpp>

// Custom messages
#include "world_utils_request.pb.h"

// @brief Command prompt
#define PROMPT "> "

/// Spawn entity
#define SPAWN           gap::msgs::WorldUtilsRequest::SPAWN
/// Move entity
#define MOVE            gap::msgs::WorldUtilsRequest::MOVE
/// Remove entity from the world
#define REMOVE          gap::msgs::WorldUtilsRequest::REMOVE
/// Start or stop physcis simulation
#define PHYSICS         gap::msgs::WorldUtilsRequest::PHYSICS
/// Pause or resume simulation
#define PAUSE           gap::msgs::WorldUtilsRequest::PAUSE
/// Get entity or world information
#define STATUS          gap::msgs::WorldUtilsRequest::STATUS

/// Spawn sphere object
#define SPHERE          gap::msgs::Object::SPHERE
/// Spawn cylinder object
#define CYLINDER        gap::msgs::Object::CYLINDER
/// Spawn box object
#define BOX             gap::msgs::Object::BOX
/// Spawn custom object
#define CUSTOM          gap::msgs::Object::CUSTOM
/// Spawn custom light object
#define CUSTOM_LIGHT    gap::msgs::Object::CUSTOM_LIGHT
/// Spawn a model included in gazebo model path
#define MODEL           gap::msgs::Object::MODEL

/// Topic monitored by WorldUtils plugin for incoming requests
#define WORLD_UTILS_TOPIC "~/gap/world_utils"
/// Directory with custom materials
#define MEDIA_DIR "media/"
/// Subdirectory with texture images
#define TEXTURES_DIR MEDIA_DIR "materials/textures/"
/// Subdirectory with material scripts
#define SCRIPTS_DIR MEDIA_DIR "materials/scripts/"
/// URI for custom material
#define TEXTURE_URI "file://materials/scripts/plugin.material"
