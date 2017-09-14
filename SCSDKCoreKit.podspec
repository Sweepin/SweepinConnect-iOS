#
# Be sure to run `pod lib lint SweepinConnect.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "SCSDKCoreKit"
  s.version          = "2.0.0"
  s.summary          = "The tools package for using SweepinConnect solutions into your app"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
SCSDKCoreKit contains general classes used by our packages
                       DESC

  s.homepage         = "https://github.com/Sweepin/SweepinConnect-iOS/SCSDKCoreKit"
  s.license          = 'MIT'
  s.author           = { "Johan Jégard" => "johan.jegard@sweepin.fr" }
  s.source           = { :git => "https://github.com/Sweepin/SCSDKCoreKit.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/SweepinApps'

  s.ios.deployment_target = '8.0'
  #s.resource = 'Resources/ProximitiesSDK.bundle'

  s.vendored_frameworks = 'SCSDKCoreKit/SCSDKCoreKit.framework'
  #realm here ?

  s.dependency 'Realm'

end
