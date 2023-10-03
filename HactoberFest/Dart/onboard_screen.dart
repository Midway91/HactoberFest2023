import 'package:flutter/material.dart';

import '../../../../data/model/on_boarding/on_boarding_content.dart';

class OnBoardingScreen extends StatefulWidget {
  const OnBoardingScreen({Key? key}) : super(key: key);

  @override
  State<OnBoardingScreen> createState() => _OnBoardingScreenState();
}

class _OnBoardingScreenState extends State<OnBoardingScreen> {
  late PageController _controller;

  List<OnBoardingContent> onBoardContent = [
    OnBoardingContent(
      title: 'A TMS for the Digital Age',
      image: 'assets/images/onboard_image_1.png',
      desc:
      'Our Transportation Management Software, built in California, is designed to automate mundane tasks empowering your team to build meaningful relationships.',
    ),
    OnBoardingContent(
      title: 'Digitize your Freight Brokerage',
      image: 'assets/images/onboard_image_2.png',
      desc:
      'Our SaaS Transportation Management Software [TMS] is purpose-built for freight brokers with design inputs from several hundred freight brokers.',
    ),
  ];
  
  @override
  void initState() {
    _controller = PageController();
    super.initState();
  }

  int _currentPage = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        children: [
          Expanded(
            flex: 4,
            child: PageView.builder(
                physics: const BouncingScrollPhysics(),
                controller: _controller,
                onPageChanged: (value) =>
                    setState(() => _currentPage = value),
                itemCount: onBoardContent.length,
                itemBuilder: (context, i) {
                  return Padding(
                    padding: const EdgeInsets.all(40.0),
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Image.asset(
                          onBoardContent[i].image,
                          height:
                          MediaQuery.of(context).size.height * 0.35,
                        ),
                        const SizedBox(height: 20),
                        Text(
                          onBoardContent[i].title,
                          textAlign: TextAlign.center,
                          style:
                          Theme.of(context).textTheme.headlineMedium,
                        ),
                        const SizedBox(height: 20),
                        Text(
                          onBoardContent[i].desc,
                          textAlign: TextAlign.center,
                          style: Theme.of(context).textTheme.bodySmall,
                        ),
                      ],
                    ),
                  );
                }),
          ),
          Expanded(
            flex: 1,
            child: Column(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: List.generate(
                    onBoardContent.length,
                        (int index) => _buildDots(
                      index: index,
                    ),
                  ),
                ),
                _currentPage + 1 == onBoardContent.length
                    ? Padding(
                    padding: const EdgeInsets.all(30),
                    child: SizedBox(
                      width: double.infinity,
                      child: ElevatedButton(
                        onPressed: () {
                        //   Navigate to next screen. i.e: LoginScreen()
                        },
                        child: const Text(
                          'GET STARTED',
                        ),
                      ),
                    )
                )
                    : Padding(
                  padding: const EdgeInsets.all(30),
                  child: Row(
                    mainAxisAlignment:
                    MainAxisAlignment.spaceBetween,
                    children: [
                      TextButton(
                        onPressed: () {
                          _controller.jumpToPage(
                              onBoardContent.length - 1);
                        },
                        child: Text(
                          'SKIP',
                          style: Theme.of(context)
                              .textTheme
                              .displayMedium,
                        ),
                        style: TextButton.styleFrom(
                          elevation: 0,
                        ),
                      ),
                      ElevatedButton(
                        onPressed: () {
                          _controller.nextPage(
                            duration:
                            const Duration(milliseconds: 200),
                            curve: Curves.easeIn,
                          );
                        },
                        child: const Text(
                          'NEXT',
                        ),
                      ),
                    ],
                  ),
                )
              ],
            ),
          ),
        ],
      ),
    );
  }

  AnimatedContainer _buildDots({
    int? index,
  }) {
    return AnimatedContainer(
      duration: const Duration(milliseconds: 200),
      decoration: BoxDecoration(
        borderRadius: const BorderRadius.all(
          Radius.circular(50),
        ),
        color: Theme.of(context).splashColor,
      ),
      margin: const EdgeInsets.only(right: 5),
      height: 10,
      curve: Curves.easeIn,
      width: _currentPage == index ? 20 : 10,
    );
  }
}
