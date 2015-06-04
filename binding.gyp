{
  "targets": [
    {
      "target_name": "launchservices",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [
        'src/main.cc',
      ],
      'conditions': [
        ['OS=="mac"', {
          'sources': [
            'src/launchservices_mac.mm'
          ],
          'link_settings': {
            'libraries': [
              '$(SDKROOT)/System/Library/Frameworks/AppKit.framework',
            ],
          }
        }]
      ]
    }
  ]
}
