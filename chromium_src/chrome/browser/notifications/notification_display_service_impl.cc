// Copyright 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "brave/components/brave_ads/browser/ads_notification_handler.h"
#include "brave/components/brave_rewards/browser/buildflags/buildflags.h"

#if BUILDFLAG(BRAVE_REWARDS_ENABLED)
 #define BRAVE_ADD_BRAVE_ADS_NOTIFICATION_HANDLER \
  AddNotificationHandler(                        \
       NotificationHandler::Type::BRAVE_ADS,      \
       std::make_unique<brave_ads::AdsNotificationHandler>(profile));
#else
#define BRAVE_ADD_BRAVE_ADS_NOTIFICATION_HANDLER \
  (void)0
#endif
#include "../../../../../../chrome/browser/notifications/notification_display_service_impl.cc"
#undef BRAVE_ADD_BRAVE_ADS_NOTIFICATION_HANDLER