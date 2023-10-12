import React from 'react'

import {useSelector} from 'react-redux'

function Mobile() {

    const mobile = useSelector((state)=> state.mobile)
  return (
    <div>
        <h1>Mobiles</h1>
        <h2>Number of Mobiles - {mobile.numberOfMobiles}</h2>
    </div>
  )
}

export default Mobile