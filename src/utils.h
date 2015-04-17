////////////////////////////////////////////////////////////////////////////////
/// @brief utilities
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2015 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Copyright 2015, ArangoDB GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGO_UTILS_H
#define ARANGO_UTILS_H 1

#include <chrono>
#include <string>
#include <vector>

#include <mesos/resources.hpp>

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

namespace arangodb {
  using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// @brief computes a FNV hash for strings
////////////////////////////////////////////////////////////////////////////////

  uint64_t FnvHashString (const vector<string>& texts);

////////////////////////////////////////////////////////////////////////////////
/// @brief splits a string
////////////////////////////////////////////////////////////////////////////////

  vector<string> split (const string&, char separator);

////////////////////////////////////////////////////////////////////////////////
/// @brief joins a vector of string
////////////////////////////////////////////////////////////////////////////////

  string join (const vector<string>&, string separator);

///////////////////////////////////////////////////////////////////////////////
/// @brief extracts diskspace from a resource
///////////////////////////////////////////////////////////////////////////////

  double diskspace (const mesos::Resources& resources);

///////////////////////////////////////////////////////////////////////////////
/// @brief extracts cpus from resources
///////////////////////////////////////////////////////////////////////////////

  double cpus (const mesos::Resources& resources);

///////////////////////////////////////////////////////////////////////////////
/// @brief extracts memory from resources
///////////////////////////////////////////////////////////////////////////////

  double memory (const mesos::Resources& resources);

///////////////////////////////////////////////////////////////////////////////
/// @brief converts system time
///////////////////////////////////////////////////////////////////////////////

  string toStringSystemTime (const chrono::system_clock::time_point&);

///////////////////////////////////////////////////////////////////////////////
/// @brief not-a-port filter
///////////////////////////////////////////////////////////////////////////////

  bool notIsPorts (const mesos::Resource& resource);

///////////////////////////////////////////////////////////////////////////////
/// @brief a-port filter
///////////////////////////////////////////////////////////////////////////////

  bool isPorts (const mesos::Resource& resource);

///////////////////////////////////////////////////////////////////////////////
/// @brief is-a-disk filter
///////////////////////////////////////////////////////////////////////////////

  bool isDisk (const mesos::Resource& resource);

///////////////////////////////////////////////////////////////////////////////
/// @brief is-not-a-disk filter
///////////////////////////////////////////////////////////////////////////////

  bool notIsDisk (const mesos::Resource& resource);

///////////////////////////////////////////////////////////////////////////////
/// @brief extracts number of avaiable ports from an offer
///////////////////////////////////////////////////////////////////////////////

  size_t numberPorts (const mesos::Offer& offer);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the disk resources
////////////////////////////////////////////////////////////////////////////////

  mesos::Resources filterIsDisk (const mesos::Resources&);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the non-disk resources
////////////////////////////////////////////////////////////////////////////////

  mesos::Resources filterNotIsDisk (const mesos::Resources&);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the persistent-volume resources
////////////////////////////////////////////////////////////////////////////////

  mesos::Resources filterIsPersistentVolume (const mesos::Resources&);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the non-port resources
////////////////////////////////////////////////////////////////////////////////

  mesos::Resources filterNotIsPorts (const mesos::Resources&);
}

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------
