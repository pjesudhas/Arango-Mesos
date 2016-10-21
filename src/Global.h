///////////////////////////////////////////////////////////////////////////////
/// @brief global defines and configuration objects
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

#ifndef GLOBAL_H
#define GLOBAL_H 1

#include <string>
#include <mesos/resources.hpp>

namespace arangodb {
  class Caretaker;
  class ArangoManager;
  class ArangoState;
  class ArangoScheduler;

// -----------------------------------------------------------------------------
// --SECTION--                                               class OperationMode
// -----------------------------------------------------------------------------

  enum class OperationMode {
    STANDALONE,
    CLUSTER
  };

// -----------------------------------------------------------------------------
// --SECTION--                                                      class Global
// -----------------------------------------------------------------------------

  class Global {

// -----------------------------------------------------------------------------
// --SECTION--                                             static public methods
// -----------------------------------------------------------------------------

    public:

////////////////////////////////////////////////////////////////////////////////
/// @brief caretaker
////////////////////////////////////////////////////////////////////////////////

      static Caretaker& caretaker ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the caretaker
////////////////////////////////////////////////////////////////////////////////

      static void setCaretaker (Caretaker*);

////////////////////////////////////////////////////////////////////////////////
/// @brief manager
////////////////////////////////////////////////////////////////////////////////

      static ArangoManager& manager ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the manager
////////////////////////////////////////////////////////////////////////////////

      static void setManager (ArangoManager*);

////////////////////////////////////////////////////////////////////////////////
/// @brief state
////////////////////////////////////////////////////////////////////////////////

      static ArangoState& state ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the state
////////////////////////////////////////////////////////////////////////////////

      static void setState (ArangoState*);

////////////////////////////////////////////////////////////////////////////////
/// @brief scheduler
////////////////////////////////////////////////////////////////////////////////

      static ArangoScheduler& scheduler ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the scheduler
////////////////////////////////////////////////////////////////////////////////

      static void setScheduler (ArangoScheduler*);

////////////////////////////////////////////////////////////////////////////////
/// @brief mode
////////////////////////////////////////////////////////////////////////////////

      static OperationMode mode ();

////////////////////////////////////////////////////////////////////////////////
/// @brief mode in lower case
////////////////////////////////////////////////////////////////////////////////

      static std::string modeLC ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the mode
////////////////////////////////////////////////////////////////////////////////

      static void setMode (OperationMode);

////////////////////////////////////////////////////////////////////////////////
/// @brief asynchronous replication flag
////////////////////////////////////////////////////////////////////////////////

      static bool asyncReplication ();

////////////////////////////////////////////////////////////////////////////////
/// @brief set asynchronous replication flag
////////////////////////////////////////////////////////////////////////////////

      static void setAsyncReplication (bool flag);

////////////////////////////////////////////////////////////////////////////////
/// @brief debugging flag to ignore some incoming offers
////////////////////////////////////////////////////////////////////////////////

      static int  ignoreOffers ();

////////////////////////////////////////////////////////////////////////////////
/// @brief debugging flags to ignore some incoming offers
////////////////////////////////////////////////////////////////////////////////

      static void setIgnoreOffers (int flags);

////////////////////////////////////////////////////////////////////////////////
/// @brief minimal resources for an agent, mesos string specification
////////////////////////////////////////////////////////////////////////////////

      static std::string minResourcesAgent ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the minimal resources for an agent
////////////////////////////////////////////////////////////////////////////////

      static void setMinResourcesAgent (std::string);

////////////////////////////////////////////////////////////////////////////////
/// @brief minimal resources for a DBserver, mesos string specification
////////////////////////////////////////////////////////////////////////////////

      static std::string minResourcesDBServer ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the minimal resources for a DBserver, mesos string spec
////////////////////////////////////////////////////////////////////////////////

      static void setMinResourcesDBServer (std::string);

////////////////////////////////////////////////////////////////////////////////
/// @brief minimal resources for a secondary, mesos string specification
////////////////////////////////////////////////////////////////////////////////

      static std::string minResourcesSecondary ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the minimal resources for a secondary, mesos string spec
////////////////////////////////////////////////////////////////////////////////

      static void setMinResourcesSecondary (std::string);

////////////////////////////////////////////////////////////////////////////////
/// @brief minimal resources for a coordinator, mesos string specification
////////////////////////////////////////////////////////////////////////////////

      static std::string minResourcesCoordinator ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the minimal resources for a coordinator
////////////////////////////////////////////////////////////////////////////////

      static void setMinResourcesCoordinator (std::string);

////////////////////////////////////////////////////////////////////////////////
/// @brief initial number of agents
////////////////////////////////////////////////////////////////////////////////

      static int nrAgents ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the initial number of agents
////////////////////////////////////////////////////////////////////////////////

      static void setNrAgents (int);

////////////////////////////////////////////////////////////////////////////////
/// @brief initial number of DBservers
////////////////////////////////////////////////////////////////////////////////

      static int nrDBServers ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the initial number of DBservers
////////////////////////////////////////////////////////////////////////////////

      static void setNrDBServers (int);

////////////////////////////////////////////////////////////////////////////////
/// @brief initial number of coordinators
////////////////////////////////////////////////////////////////////////////////

      static int nrCoordinators ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the initial number of coordinators
////////////////////////////////////////////////////////////////////////////////

      static void setNrCoordinators (int);

////////////////////////////////////////////////////////////////////////////////
/// @brief role
////////////////////////////////////////////////////////////////////////////////

      static std::string role ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the role
////////////////////////////////////////////////////////////////////////////////

      static void setRole (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief frameworkName
////////////////////////////////////////////////////////////////////////////////

      static std::string frameworkName ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the frameworkName
////////////////////////////////////////////////////////////////////////////////

      static void setFrameworkName (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief principal
////////////////////////////////////////////////////////////////////////////////
      static std::string principal ();

      static mesos::Resource::ReservationInfo createReservation ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the principal
////////////////////////////////////////////////////////////////////////////////

      static void setPrincipal (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief master url
////////////////////////////////////////////////////////////////////////////////

      static const std::string& masterUrl ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the master url
////////////////////////////////////////////////////////////////////////////////

      static void setMasterUrl (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief volume path
////////////////////////////////////////////////////////////////////////////////

      static const std::string& volumePath ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the volume path
////////////////////////////////////////////////////////////////////////////////

      static void setVolumePath (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief secondaries with dbservers flag
////////////////////////////////////////////////////////////////////////////////

      static bool secondariesWithDBservers ();

////////////////////////////////////////////////////////////////////////////////
/// @brief secondaries with dbservers flag
////////////////////////////////////////////////////////////////////////////////

      static void setSecondariesWithDBservers (bool);

////////////////////////////////////////////////////////////////////////////////
/// @brief coordinators with dbservers flag
////////////////////////////////////////////////////////////////////////////////

      static bool coordinatorsWithDBservers ();

////////////////////////////////////////////////////////////////////////////////
/// @brief coordinators with dbservers flag
////////////////////////////////////////////////////////////////////////////////

      static void setCoordinatorsWithDBservers (bool);

////////////////////////////////////////////////////////////////////////////////
/// @brief secondary on same agent
////////////////////////////////////////////////////////////////////////////////

      static bool secondarySameServer ();

////////////////////////////////////////////////////////////////////////////////
/// @brief secondary on same agent
////////////////////////////////////////////////////////////////////////////////

      static void setSecondarySameServer (bool);

////////////////////////////////////////////////////////////////////////////////
/// @brief docker image to use
////////////////////////////////////////////////////////////////////////////////

      static const std::string& arangoDBImage();

////////////////////////////////////////////////////////////////////////////////
/// @brief docker image to use
////////////////////////////////////////////////////////////////////////////////

      static void setArangoDBImage (const std::string&);

////////////////////////////////////////////////////////////////////////////////
/// @brief run docker image privileged
////////////////////////////////////////////////////////////////////////////////

      static bool arangoDBPrivilegedImage();

////////////////////////////////////////////////////////////////////////////////
/// @brief run docker image privileged
////////////////////////////////////////////////////////////////////////////////

      static void setArangoDBPrivilegedImage(bool f);

////////////////////////////////////////////////////////////////////////////////
/// @brief force pull the arangodb image
////////////////////////////////////////////////////////////////////////////////

      static bool arangoDBForcePullImage();

////////////////////////////////////////////////////////////////////////////////
/// @brief set pulling the arangodb forcefully
////////////////////////////////////////////////////////////////////////////////

      static void setArangoDBForcePullImage(bool f);

////////////////////////////////////////////////////////////////////////////////
/// @brief frameworkPort
////////////////////////////////////////////////////////////////////////////////

      static int frameworkPort();

////////////////////////////////////////////////////////////////////////////////
/// @brief set frameworkPort
////////////////////////////////////////////////////////////////////////////////

      static void setFrameworkPort(int);

////////////////////////////////////////////////////////////////////////////////
/// @brief webuiPort
////////////////////////////////////////////////////////////////////////////////

      static int webuiPort();

////////////////////////////////////////////////////////////////////////////////
/// @brief set webuiPort
////////////////////////////////////////////////////////////////////////////////

      static void setWebuiPort(int);

      static bool startReverseProxy();

      static void setArangoDBEnterpriseKey(std::string const& arangoDBEnterpriseKey);
      static std::string arangoDBEnterpriseKey();

      static void setArangoDBJwtSecret(std::string const& arangoDBJwtSecret);
      static std::string arangoDBJwtSecret();
  };
}

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------
