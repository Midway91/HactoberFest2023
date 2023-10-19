// import React, { useState, useRef } from 'react';
// import { Row, Col, Form, Button } from 'react-bootstrap';
// import './Right.css';

// function Right({ buttonText }) {
//     const [showTooltip, setShowTooltip] = useState(false);
//     const [tooltipStyles, setTooltipStyles] = useState({
//         fontSize: '15px',
//         padding: '8px',
//         backgroundColor: '#ff9900',
//         color: '#fff',
//         borderRadius: '5px',
//         width: '300px',
//         arrowWidth: '5px',
//         arrowHeight: '5px',
//     });
//     const [tooltipText, setTooltipText] = useState('');
//     const [selectedButton, setSelectedButton] = useState('');

//     const buttonRefs = {
//         button1: useRef(null),
//         button2: useRef(null),
//         button3: useRef(null),
//         button4: useRef(null),
//         button5: useRef(null),
//     };

//     const handleMouseEnter = buttonKey => {
//         setSelectedButton(buttonKey);
//         setShowTooltip(true);
//     };

//     const handleMouseLeave = () => {
//         setShowTooltip(false);
//     };

//     const handleStyleChange = (property, value) => {
//         setTooltipStyles(prevStyles => ({
//             ...prevStyles,
//             [property]: value,
//         }));
//     };

//     const handleTextChange = e => {
//         setTooltipText(e.target.value);
//     };

//     const handleButtonChange = e => {
//         setSelectedButton(e.target.value);
//     };

//     const positionTooltip = () => {
//         if (buttonRefs[selectedButton].current) {
//             const buttonRect = buttonRefs[selectedButton].current.getBoundingClientRect();
//             return {
//                 top: buttonRect.bottom + 10 + 'px',
//                 left: buttonRect.left + 'px',
//             };
//         }
//         return {};
//     };

//     return (
//         <div className="dynamic-tooltip-container">
//             <Row>
//                 <Col style={{ 'margin': '40px', 'padding': '31px', 'background': '#ECF0F1', 'borderRadius': '10px', 'fontWeight': 'bold' }}>
//                     <div className="style-inputs">
//                         <Form.Group as={Row} controlId="formSelect">
//                             <Form.Label column sm={12} style={{ 'paddingRight': '665px' }}>
//                                 Target element
//                             </Form.Label>
//                             <Col sm={12}>
//                                 <Form.Control as="select" onChange={handleButtonChange}>
//                                     <option value="option1">Button 1</option>
//                                     <option value="option2">Button 2</option>
//                                     <option value="option3">Button 3</option>
//                                     <option value="option4">Button 4</option>
//                                     <option value="option5">Button 5</option>
//                                 </Form.Control>
//                             </Col>
//                         </Form.Group>
//                         <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                             <Form.Label style={{ 'paddingRight': '675px', 'paddingTop': '10px' }}>Tooltip text</Form.Label>
//                             <Form.Control type="text" placeholder="Input" value={tooltipText}
//                                 onChange={handleTextChange} />
//                         </Form.Group>
//                         <Row>
//                             <Col>
//                                 <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                                     <Form.Label style={{ 'paddingRight': '285px', 'paddingTop': '10px' }}>Text size</Form.Label>
//                                     <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('fontSize', e.target.value)} />
//                                 </Form.Group>
//                             </Col>
//                             <Col>
//                                 <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                                     <Form.Label style={{ 'paddingRight': '290px', 'paddingTop': '10px' }}>Padding</Form.Label>
//                                     <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('padding', e.target.value)} />
//                                 </Form.Group>
//                             </Col>
//                         </Row>
//                         <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                             <Form.Label style={{ 'paddingRight': '675px', 'paddingTop': '10px' }}>Text colour</Form.Label>
//                             <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('color', e.target.value)} />
//                         </Form.Group>
//                         <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                             <Form.Label style={{ 'paddingRight': '625px', 'paddingTop': '10px' }}>Background colour</Form.Label>
//                             <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('backgroundColor', e.target.value)} />
//                         </Form.Group>
//                         <Row>
//                             <Col>
//                                 <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                                     <Form.Label style={{ 'paddingRight': '255px', 'paddingTop': '10px' }}>Corner radius</Form.Label>
//                                     <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('borderRadius', e.target.value)} />
//                                 </Form.Group>
//                             </Col>
//                             <Col>
//                                 <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                                     <Form.Label style={{ 'paddingRight': '235px', 'paddingTop': '10px' }}>Tooltip width</Form.Label>
//                                     <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('width', e.target.value)} />
//                                 </Form.Group>
//                             </Col>
//                         </Row>
//                         <Row>
//                             <Col>
//                                 <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                                     <Form.Label style={{ 'paddingRight': '255px', 'paddingTop': '10px' }}>Arrow width</Form.Label>
//                                     <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('arrowWidth', e.target.value)} />
//                                 </Form.Group>
//                             </Col>
//                             <Col>
//                                 <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
//                                     <Form.Label style={{ 'paddingRight': '235px', 'paddingTop': '10px' }}>Arrow height</Form.Label>
//                                     <Form.Control type="text" placeholder="Input" onChange={e => handleStyleChange('arrowHeight', e.target.value)} />
//                                 </Form.Group>
//                             </Col>
//                         </Row>
//                         {/* <input
//                             type="text"
//                             placeholder="Padding"
//                             onChange={e => handleStyleChange('padding', e.target.value)}
//                         /> */}
//                         {/* <input
//                             type="text"
//                             placeholder="Background Color"
//                             onChange={e => handleStyleChange('backgroundColor', e.target.value)}
//                         /> */}
//                         {/* <input
//                             type="text"
//                             placeholder="Text Color"
//                             onChange={e => handleStyleChange('color', e.target.value)}
//                         /> */}
//                     </div>
//                 </Col>
//                 <Col>
//                     <div className="mobile-screen">
//                         <div className="app-content">
//                             <Row>
//                                 <Col>
//                                     <Button
//                                         ref={buttonRefs.button1}
//                                         variant="light"
//                                         className="dynamic-tooltip-button"
//                                         onMouseEnter={() => handleMouseEnter('button1')}
//                                         onMouseLeave={handleMouseLeave}
//                                     >
//                                         Button 1
//                                     </Button>
//                                 </Col>
//                                 <Col>
//                                     <Button
//                                         ref={buttonRefs.button2}
//                                         variant="light"
//                                         className="dynamic-tooltip-button"
//                                         onMouseEnter={() => handleMouseEnter('button2')}
//                                         onMouseLeave={handleMouseLeave}
//                                     >
//                                         Button 2
//                                     </Button>
//                                 </Col>
//                             </Row>
//                             <Button
//                                 ref={buttonRefs.button3}
//                                 variant="light"
//                                 className="dynamic-tooltip-button"
//                                 onMouseEnter={() => handleMouseEnter('button3')}
//                                 onMouseLeave={handleMouseLeave}
//                                 style={{ marginTop: '80px' }}
//                             >
//                                 Button 3
//                             </Button>
//                             <Row>
//                                 <Col>
//                                     <Button
//                                         ref={buttonRefs.button4}
//                                         variant="light"
//                                         className="dynamic-tooltip-button"
//                                         onMouseEnter={() => handleMouseEnter('button4')}
//                                         onMouseLeave={handleMouseLeave}
//                                     >
//                                         Button 4
//                                     </Button>
//                                 </Col>
//                                 <Col>
//                                     <Button
//                                         ref={buttonRefs.button5}
//                                         variant="light"
//                                         className="dynamic-tooltip-button"
//                                         onMouseEnter={() => handleMouseEnter('button5')}
//                                         onMouseLeave={handleMouseLeave}
//                                     >
//                                         Button 5
//                                     </Button>
//                                 </Col>
//                             </Row>

//                             {selectedButton && selectedButton === buttonText && showTooltip && (
//                                 <div
//                                     className="dynamic-tooltip"
//                                     style={{
//                                         ...positionTooltip(),
//                                         padding: tooltipStyles.padding,
//                                         backgroundColor: tooltipStyles.backgroundColor,
//                                         color: tooltipStyles.color,
//                                         fontSize: tooltipStyles.fontSize,
//                                         borderRadius: tooltipStyles.borderRadius,
//                                         width: tooltipStyles.width,
//                                         maxWidth: tooltipStyles.width,
//                                     }}
//                                 >
//                                     {tooltipText}
//                                     <div
//                                         className="tooltip-arrow"
//                                         style={{ borderWidth: tooltipStyles.arrowHeight }}
//                                     ></div>
//                                 </div>
//                             )}
//                         </div>
//                     </div>
//                 </Col>
//             </Row>
//         </div>
//     );
// }

// export default Right;
