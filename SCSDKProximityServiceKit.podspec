#
# Be sure to run `pod lib lint SweepinConnect.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "SCSDKProximityServiceKit"
  s.version          = "2.0.4"
  s.summary          = "SweepinConnect Proximity Service solutions package"

  s.description      = <<-DESC
Sweepin manager let you create your campaigns online in no time and broadcast to your audience.
Watch the analytics data on our charts, and get the visitor's traffic in real time.

Our SDK is easy to integrate and highly customizable.

Automate the campaign creation process : use our API to connect your existing back office or CRM !

                       DESC

  s.homepage         = "https://github.com/Sweepin/SweepinConnect-iOS/"
  s.license          = 'MIT'
  s.author           = { "Johan Jégard" => "johan.jegard@sweepin.fr" }
  s.source           = { :git => "https://github.com/Sweepin/SweepinConnect-iOS.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/SweepinApps'

  s.ios.deployment_target = '8.0'

  s.vendored_frameworks = 'SCSDKProximityServiceKit/SCSDKProximityServiceKit.framework'
  s.dependency 'SCSDKCoreKit'
  
end
