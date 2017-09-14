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
  s.summary          = "Tools package for SweepinConnect"

  s.description      = <<-DESC
SCSDKCoreKit contains general classes used by our packages.
                       DESC

  s.homepage         = "https://github.com/Sweepin/SweepinConnect-iOS/"
  s.license          = 'MIT'
  s.author           = { "Johan Jégard" => "johan.jegard@sweepin.fr" }
  s.source           = { :git => "https://github.com/Sweepin/SweepinConnect-iOS.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/SweepinApps'

  s.ios.deployment_target = '8.0'

  s.vendored_frameworks = 'SCSDKCoreKit/SCSDKCoreKit.framework'

  s.dependency 'Realm'

end
