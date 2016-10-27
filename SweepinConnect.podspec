#
# Be sure to run `pod lib lint SweepinConnect.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "SweepinConnect"
  s.version          = "0.1.21"
  s.summary          = "The new era of location-based marketing"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
Sweepin manager let you create your campaigns online in no time and broadcast to your audience.
Watch the analytics data on our charts, and get the visitor's traffic in real time.

Our SDK is easy to integrate and highly customizable.

Automate the campaign creation process : use our API to connect your existing back office or CRM !
                       DESC

  s.homepage         = "https://github.com/Sweepin/SweepinConnect-iOS"
  s.license          = 'MIT'
  s.author           = { "Johan Jégard" => "johan.jegard@sweepin.fr" }
  s.source           = { :git => "https://github.com/Sweepin/SweepinConnect-iOS.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/SweepinApps'

  s.ios.deployment_target = '7.0'
  s.resource = 'Resources/ProximitiesSDK.bundle'

  s.vendored_frameworks = 'SweepinConnect/ProximitiesSDK.framework'
  s.frameworks = 'UIKit', 'CoreBluetooth', 'CoreLocation', 'SystemConfiguration', 'Foundation', 'AVFoundation', 'AVKit', 'CoreMedia'
  s.libraries = 'sqlite3.0'

end
